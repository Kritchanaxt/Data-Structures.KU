# Data Structures in C 
- **Data Structures** คือ วิธีการจัดเก็บและจัดการข้อมูลในคอมพิวเตอร์เพื่อให้สามารถเข้าถึงและแก้ไขข้อมูลได้อย่างมีประสิทธิภาพ ตัวอย่างของโครงสร้างข้อมูล ได้แก่ อาร์เรย์, ลิงก์ลิสต์, สแตก, คิว, และต้นไม้

## Array 
- **Array** เป็นโครงสร้างข้อมูลพื้นฐานในภาษา C ที่ใช้ในการจัดเก็บชุดของข้อมูลประเภทเดียวกันในตำแหน่งที่ต่อเนื่องกันในหน่วยความจำ โดยการเข้าถึงข้อมูลในอาเรย์สามารถทำได้โดยใช้ดัชนี (index)

<img width="1000" alt="Array1" src="https://github.com/user-attachments/assets/21e2ec50-7ebc-4384-8e31-9910f5834381">  

### การประกาศ Array 
>  ***data_type array_name[array_size];***
- **data_type:** ชนิดข้อมูลของสมาชิกในอาร์เรย์ (เช่น int, float, char เป็นต้น)
- **array_name:** ชื่อของอาร์เรย์
- **array_size:** ขนาดของอาร์เรย์ (จำนวนสมาชิกที่ต้องการเก็บ)
- เช่น **int numbers[5];**

### 2 Dimensional Array 
<img width="1000" alt="Array1" src="https://github.com/user-attachments/assets/a0462539-d61f-4cb3-995e-d9c33f178b3a">  

### การใช้งาน Array 
- **การเข้าถึงสมาชิก:** สามารถใช้ดัชนี (index) เพื่อเข้าถึงสมาชิกในอาร์เรย์ เช่น array[index]
- **การกำหนดค่า:** สามารถกำหนดค่าให้กับสมาชิกได้โดยการใช้ดัชนี เช่น array[index] = value
- **การวนลูป:** สามารถใช้ลูปเพื่อทำงานกับสมาชิกทั้งหมดของอาร์เรย์ เช่น การแสดงผลทุกสมาชิกในอาร์เรย์
  
## Node 
- **Node** เป็นหน่วยพื้นฐานที่ใช้ในการจัดเก็บข้อมูลและเชื่อมโยงไปยังโหนดอื่นๆ 

<img width="1000" alt="Node" src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRJ5F4EBEjzdiJ5sNTIuvsjiz1lCJVj2Q-vMA&s">  

### Node แต่ละตัวมีสองส่วนหลัก
- **Data (ข้อมูล):** ใช้ในการจัดเก็บข้อมูลที่เราต้องการ เช่น ตัวเลข ข้อความ หรือข้อมูลประเภทอื่น
- **Pointer (ตัวชี้):** ใช้ในการเชื่อมโยงโหนดปัจจุบันไปยังโหนดถัดไปในลิสต์ (หรือโหนดก่อนหน้าในกรณีของลิงก์ลิสต์แบบสองทิศทาง)
  
### การใช้งานของ Node 
- โหนดเป็นหน่วยที่เชื่อมต่อกันในลิงก์ลิสต์โดยการอ้างอิงถึงกัน ทำให้สามารถสร้างลิสต์ที่มีขนาดแตกต่างกันตามความต้องการของโปรแกรม

## Linked List
- **Linked List** คือโครงสร้างข้อมูลเชิงเส้นที่ใช้ในการจัดเก็บชุดของข้อมูลซึ่งองค์ประกอบแต่ละตัวจะเชื่อมต่อกันโดยการอ้างอิง (pointer) ในแต่ละองค์ประกอบของลิงก์ลิสต์จะมีสองส่วนหลัก คือ ข้อมูล (data) และตัวชี้ (pointer) ที่เชื่อมโยงไปยังองค์ประกอบถัดไปในลิสต์

<img width="1000" alt="linklist" src="https://media.geeksforgeeks.org/wp-content/uploads/20220712172013/Singlelinkedlist.png">

- **Next:** ใช้ในการเชื่อมต่อ node แต่ละตัวใน Linked List เข้าด้วยกัน
- **Head/Start:** เป็นจุดเริ่มต้นของ Linked List และใช้ในการเข้าถึง node ตัวแรก

### 1. Singly Linked List
- Singly Linked List เป็น Linked List พื้นฐานที่สุด แต่ละโหนดมีพอยน์เตอร์ที่ชี้ไปยังโหนดถัดไปเท่านั้น

<img width="1000" alt="Screenshot 2567-07-25 at 13 52 57" src="https://github.com/user-attachments/assets/ac79e284-104e-471e-8a7c-7afd6e497419">

### 2. Doubly Linked List
- Doubly Linked List แต่ละโหนดมีสองพอยน์เตอร์ ชี้ไปยังโหนดก่อนหน้าและโหนดถัดไป ทำให้สามารถเดินทางทั้งไปข้างหน้าและย้อนกลับได้

<img width="1000" alt="Screenshot 2567-07-25 at 13 53 13" src="https://github.com/user-attachments/assets/697abcbf-759a-495a-a744-d27d9fc13df7">

### 3. Circular Linked List
- Circular Linked List เป็น Singly Linked List ที่โหนดสุดท้ายชี้กลับไปที่โหนดแรก ทำให้โครงสร้างเชื่อมต่อเป็นวงกลม

<img width="1000" alt="Screenshot 2567-07-25 at 13 53 39" src="https://github.com/user-attachments/assets/2faef863-39ed-4073-a348-f4a0c52fe68a">

### 4. Circular Doubly Linked List
- Circular Doubly Linked List เป็น Doubly Linked List ที่โหนดสุดท้ายชี้กลับไปยังโหนดแรกและโหนดแรกชี้ไปยังโหนดสุดท้าย ทำให้เชื่อมต่อเป็นวงกลมทั้งไปข้างหน้าและย้อนกลับ

<img width="1000" alt="Screenshot 2567-07-25 at 13 53 49" src="https://github.com/user-attachments/assets/9f68db83-a718-4ded-a370-204554e9c3ef">

### กรณีการใช้งาน Linked List
 1. **จัดการหน่วยความจำที่ไม่ต่อเนื่อง:** ใช้เมื่อขนาดของข้อมูลไม่แน่นอน เช่น การจัดการรายการในโปรแกรมที่ต้องการเพิ่มหรือลบข้อมูลบ่อยๆ
 2. **แทรกและลบข้อมูลอย่างมีประสิทธิภาพ:** เพิ่มหรือลบข้อมูลง่ายกว่าการใช้อาร์เรย์ โดยไม่ต้องเลื่อนข้อมูล
 3. **จัดเก็บข้อมูลที่ต้องการการเข้าถึงแบบลำดับ:** ใช้สำหรับรายการที่ต้องการการเข้าถึงข้อมูลแบบเป็นลำดับ เช่น รายการเพลง
 4. **สร้างโครงสร้างข้อมูลที่ซับซ้อน:** ใช้เป็นฐานในการสร้างโครงสร้างข้อมูลที่ซับซ้อน เช่น ต้นไม้หรือกราฟ
 5. **การเดินทางในทิศทางทั้งสอง:** ใช้ลิงก์ลิสต์แบบสองทิศทางเพื่อการเดินทางไปข้างหน้าและย้อนกลับ

## Stack
- **Stack** คือโครงสร้างข้อมูลเชิงเส้นที่ทำงานตามหลักการ Last In, First Out (LIFO) หมายความว่าองค์ประกอบที่ถูกเพิ่มเข้ามาเป็นองค์ประกอบสุดท้ายจะถูกนำออกเป็นองค์ประกอบแรก สามารถนึกภาพได้ว่าเหมือนกับกองจานที่เราสามารถเพิ่มหรือเอาจานออกจากด้านบนสุดเท่านั้น

<img width="1000" alt="Stack1" src="https://github.com/user-attachments/assets/7824c5ec-c513-465b-8129-2a7cecc7eaa4"> 

### การดำเนินการหลักของ Stack
- **Push:** เพิ่มองค์ประกอบไปที่ด้านบนสุดของ stack
- **Pop:** นำองค์ประกอบออกจากด้านบนสุดของ stack
- **Peek:** ดูองค์ประกอบที่อยู่ด้านบนสุดของ stack โดยไม่ต้องนำออก
- **isEmpty:** ตรวจสอบว่า stack ว่างหรือไม่

<img width="1000"  alt="Stack2" src="https://github.com/user-attachments/assets/e851c382-a3a9-443d-adaf-0bdd3f963a5d">
  
### กรณีการใช้งาน Stack
- การจัดการการเรียกฟังก์ชัน (recursion)
- กลไกการย้อนกลับ (undo) ในโปรแกรมแก้ไขข้อความ
- การวิเคราะห์ไวยากรณ์ (เช่น การตรวจสอบการจับคู่ของวงเล็บ)
- อัลกอริทึม backtracking (เช่น การแก้ปัญหาเขาวงกต)

## Queue
- **Queue** คือโครงสร้างข้อมูลพื้นฐานที่ทำงานบนหลักการ "เข้าก่อนออกก่อน" (First-In-First-Out, FIFO) หมายถึงข้อมูลที่ถูกเพิ่มเข้าไปในคิวก่อนจะถูกนำออกมาก่อน

<img width="1000"  alt="Queue1" src="https://github.com/user-attachments/assets/3a1865c3-f5df-4e3f-a46b-9cb0e52ce0c6"> 

### Front (Head):
- ตำแหน่งที่เก็บข้อมูลตัวแรกสุดในคิว
- ใช้สำหรับการนำข้อมูลออกจากคิว (dequeue)
- ข้อมูลที่ถูกเพิ่มเข้ามาก่อนจะถูกนำออกก่อน (หลักการ FIFO(Firt-In, Firt-Out))

### Rear (Back/Tail):
- ตำแหน่งที่เก็บข้อมูลตัวสุดท้ายในคิว
- ใช้สำหรับการเพิ่มข้อมูลเข้าคิว (enqueue)
- ข้อมูลที่ถูกเพิ่มเข้ามาหลังสุดจะถูกนำออกหลังสุด

### การใช้งาน Queue
- **Enqueue/insert (เพิ่มข้อมูล):** เพิ่มข้อมูลใหม่ที่ปลายคิว
- **Dequeue/delete (นำข้อมูลออก):** นำข้อมูลจากหัวคิวออก
- **Display/peek:** แสดงข้อมูลทั้งหมดในคิว

<img width="1000"  alt="Queue2" src="https://github.com/user-attachments/assets/a6bf85d8-2f0f-4713-8d0e-bc5edcc856e9">

### กรณีการใช้งาน Queue
- **การจัดการคิวของงาน:** ในระบบปฏิบัติการ การจัดการกับงานที่ต้องทำให้เสร็จตามลำดับ
- **การจัดการกับการพิมพ์:** ในระบบที่มีการพิมพ์เอกสารจากหลายแหล่ง ข้อมูลของเอกสารจะถูกจัดเก็บในคิว
- **การจัดการกับการสื่อสารข้อมูล:** การส่งข้อมูลผ่านเครือข่าย ที่ข้อมูลจะถูกจัดเก็บในคิวก่อนการส่งต่อไปยังปลายทาง
- **การจัดการเหตุการณ์ในเกม:** การจัดการกับเหตุการณ์ที่เกิดขึ้นในเกมตามลำดับ

