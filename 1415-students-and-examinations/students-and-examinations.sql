SELECT
    s.student_id,
    s.student_name,
    sub.subject_name,
    COUNT(e.subject_name) AS attended_exams
FROM Students s

-- Create every possible student-subject combination.
-- Example: Alice-Math, Alice-Physics, Bob-Math, Bob-Physics.
CROSS JOIN Subjects sub

-- Match actual exam attendance.
-- LEFT JOIN keeps student-subject combinations even when
-- the student has not attended any exam for that subject.
LEFT JOIN Examinations e
    ON s.student_id = e.student_id
    AND sub.subject_name = e.subject_name

-- Create one group for each student and subject
-- so we can count exams separately for each combination.
GROUP BY
    s.student_id,
    s.student_name,
    sub.subject_name

-- Display results in ascending student ID, then subject name.
ORDER BY
    s.student_id,
    sub.subject_name;