-- Keep a log of any SQL queries you execute as you solve the mystery.

-- code to find the description of the crime scene
SELECT * FROM crime_scene_reports WHERE day = 28 AND month = 7 AND street = 'Humphrey Street';

-- interviews gave us proof that the robbery took place at 10:15 AM and 3 witness were there
SELECT * FROM interviews WHERE month = 7 AND day = 28;

--the description of euegene told us that they saw the robber take mony from the atm at leggett street that morning
select * from atm_transactions where day = 28 and month = 7 and atm_location = 'Leggett Street';

--taking the names of people who used the atm that morning
SELECT * FROM people WHERE id IN ( SELECT person_id FROM bank_accounts WHERE account_number IN (select account_number from atm_transactions where day = 28 and month = 7 and atm_location = 'Leggett Street'));

-- track phone calls on 28th july and the duration should be lesss than a min
SELECT * FROM phone_calls WHERE month = 7 AND day = 28 AND duration < 60;

--add names to call list of callers
SELECT p.name, pc.caller, pc.receiver, pc.year, pc.month, pc.day, pc.duration
FROM phone_calls pc
JOIN people p ON pc.caller = p.phone_number
WHERE pc.month = 7 AND pc.day = 28 AND pc.duration < 60;

--witness 1 ruth bakery footage
SELECT * FROM bakery_security_logs WHERE month = 7 AND day = 28 AND hour=10 AND minute BETWEEN 15 AND 25 ;

-- check against license plate
SELECT p.name, bsl.activity, bsl.license_plate, bsl.year, bsl.month, bsl.day, bsl.hour, bsl.minute FROM bakery_security_logs bsl JOIN people p ON p.license_plate = bsl.license_plate WHERE bsl.month = 7 AND bsl.day = 28 AND bsl.hour =10 AND bsl.year = 2021 AND bsl.minute BETWEEN 15 AND 25;

--add name of withdraws from atm
SELECT a.*, p.name
FROM atm_transactions a
JOIN bank_accounts b ON a.account_number = b.account_number
JOIN people p ON b.person_id = p.id
WHERE a.atm_location = 'Leggett Street' AND a.year = 2021 AND a.month = 7 AND a.day = 28 AND a.transaction_type = 'Withdraw';


--explore airports to find fiftyville
SELECT * FROM airports;

--found fiftyville id(8) explore flights out
SELECT f.*, origin.full_name AS origin_airport, destination.full_name AS destination_airport
FROM flights f
JOIN airports origin oN f.origin_airport_id = origin.id
JOIN airports destination ON f.destination_airport_id = destination.id
WHERE origin.id = 8 AND f.year - 2021 AND f.month - 7 AND f.day - 29
ORDER BY f.hour, f.minute;

--combine info fron all three witnesses
--i think that the thief is bruce and the acomplise is robin and theuy went to new york
