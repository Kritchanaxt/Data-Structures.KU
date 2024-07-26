# Data Structures in C 

## Stack
- Stack คือโครงสร้างข้อมูลเชิงเส้นที่ทำงานตามหลักการ Last In, First Out (LIFO) หมายความว่าองค์ประกอบที่ถูกเพิ่มเข้ามาเป็นองค์ประกอบสุดท้ายจะถูกนำออกเป็นองค์ประกอบแรก สามารถนึกภาพได้ว่าเหมือนกับกองจานที่เราสามารถเพิ่มหรือเอาจานออกจากด้านบนสุดเท่านั้น

**การดำเนินการหลักของ Stack:**
- Push: เพิ่มองค์ประกอบไปที่ด้านบนสุดของ stack
- Pop: นำองค์ประกอบออกจากด้านบนสุดของ stack
- Peek: ดูองค์ประกอบที่อยู่ด้านบนสุดของ stack โดยไม่ต้องนำออก
- isEmpty: ตรวจสอบว่า stack ว่างหรือไม่
  

<img width="500" hight="500" alt="Stack1" src="https://github.com/user-attachments/assets/7824c5ec-c513-465b-8129-2a7cecc7eaa4">  <img width="500"  hight="500" alt="Stack2" src="https://github.com/user-attachments/assets/e851c382-a3a9-443d-adaf-0bdd3f963a5d">

**กรณีการใช้งาน Stack:**
- การจัดการการเรียกฟังก์ชัน (recursion)
- กลไกการย้อนกลับ (undo) ในโปรแกรมแก้ไขข้อความ
- การวิเคราะห์ไวยากรณ์ (เช่น การตรวจสอบการจับคู่ของวงเล็บ)
- อัลกอริทึม backtracking (เช่น การแก้ปัญหาเขาวงกต)

## Linked List
- Linked List คือโครงสร้างข้อมูลเชิงเส้นที่ใช้ในการจัดเก็บชุดของข้อมูลซึ่งองค์ประกอบแต่ละตัวจะเชื่อมต่อกันโดยการอ้างอิง (pointer) ในแต่ละองค์ประกอบของลิงก์ลิสต์จะมีสองส่วนหลัก คือ ข้อมูล (data) และตัวชี้ (pointer) ที่เชื่อมโยงไปยังองค์ประกอบถัดไปในลิสต์

### 1. Singly Linked List
Singly Linked List เป็น Linked List พื้นฐานที่สุด แต่ละโหนดมีพอยน์เตอร์ที่ชี้ไปยังโหนดถัดไปเท่านั้น

<img width="1000" alt="Screenshot 2567-07-25 at 13 52 57" src="https://github.com/user-attachments/assets/ac79e284-104e-471e-8a7c-7afd6e497419">

### 2. Doubly Linked List
Doubly Linked List แต่ละโหนดมีสองพอยน์เตอร์ ชี้ไปยังโหนดก่อนหน้าและโหนดถัดไป ทำให้สามารถเดินทางทั้งไปข้างหน้าและย้อนกลับได้

<img width="1000" alt="Screenshot 2567-07-25 at 13 53 13" src="https://github.com/user-attachments/assets/697abcbf-759a-495a-a744-d27d9fc13df7">

### 3. Circular Linked List
Circular Linked List เป็น Singly Linked List ที่โหนดสุดท้ายชี้กลับไปที่โหนดแรก ทำให้โครงสร้างเชื่อมต่อเป็นวงกลม

<img width="1000" alt="Screenshot 2567-07-25 at 13 53 39" src="https://github.com/user-attachments/assets/2faef863-39ed-4073-a348-f4a0c52fe68a">

### 4. Circular Doubly Linked List
Circular Doubly Linked List เป็น Doubly Linked List ที่โหนดสุดท้ายชี้กลับไปยังโหนดแรกและโหนดแรกชี้ไปยังโหนดสุดท้าย ทำให้เชื่อมต่อเป็นวงกลมทั้งไปข้างหน้าและย้อนกลับ

<img width="1000" alt="Screenshot 2567-07-25 at 13 53 49" src="https://github.com/user-attachments/assets/9f68db83-a718-4ded-a370-204554e9c3ef">



