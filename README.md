# Software_Engineering_2_Project

In this project, we aim to design, implement and test a computer vision based class attendance monitoring system.

Our goal was to develop a system to function in a classroom in which a camera is placed at a position where faces of all 
students attending the lecture can be captured at any time during the lecture. The camera captures the class room at each 
defined time instant; the photo taken will then be processed to record the presence of students.The technique we used in order 
to achieve this goal was Linear Discriminant Analysis (LDA), which can be derived from an idea suggested by R.A. Fisher in 1936. 
When LDA is used to find the subspace representation of a set of face images, the resulting basis vectors defining that space are
known as Fisherfaces.

This system is designed to mark the attendance of a class during a lecture period using facial recognition software. The system is 
able to determine whether a student is either present for the lecture, late for the lecture, left the lecture early or absent for the 
lecture. The attendance statistics for the entire semester can also be viewed for each student.
The system captures an image of the class four times with a 10 minute interval between each image captured. From the captured image, 
faces are detected, recognised and processed. The results are stored in a database. After the final capture, the results from the four 
captures are processed and the respective presence is allocated to the student for that lecture day. For example; if a student was 
recognized in all four captures, that student is marked present for that lecture day.
