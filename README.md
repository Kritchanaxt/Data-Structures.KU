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
- **Queue** คือโครงสร้างข้อมูลพื้นฐานที่ทำงานบนหลักการ "เข้าก่อนออกก่อน" FIFO(First-In-First-Out) หมายถึงข้อมูลที่ถูกเพิ่มเข้าไปในคิวก่อนจะถูกนำออกมาก่อน

<img width="1000"  alt="Queue1" src="https://github.com/user-attachments/assets/3a1865c3-f5df-4e3f-a46b-9cb0e52ce0c6"> 

### Front (Head):
- ตำแหน่งที่เก็บข้อมูลตัวแรกสุดในคิว
- ใช้สำหรับการนำข้อมูลออกจากคิว (dequeue)
- ข้อมูลที่ถูกเพิ่มเข้ามาก่อนจะถูกนำออกก่อน (หลักการ FIFO)

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

## Trees

![Treedatastructure](https://github.com/user-attachments/assets/23c5fa76-00fe-41b4-959b-72b3c52d6d46)
![typoes1-768](https://github.com/user-attachments/assets/86d46646-4e75-4cb8-b82a-e18652df0790)
![Figure-5 2 7 -Linked-representation-for-the-binary-tree](https://github.com/user-attachments/assets/d50f25a1-c57f-426f-9c5d-f025d0c12bae)

<img width="1000" alt="BST" src="data:image/png;base64,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
  ">  


### โครงสร้างข้อมูลแบบลำดับชั้น (Hierarchical Structure)
- โครงสร้างข้อมูลแบบลำดับชั้นจัดเก็บข้อมูลเป็นลำดับชั้น มีการเชื่อมโยงกันระหว่างโหนด (Node).
- โหนดมีโหนดราก (Root Node) เป็นโหนดเริ่มต้น และมีลูกโหนด (Child Nodes) เป็นโหนดย่อยที่เชื่อมต่อกันในรูปแบบต้นไม้.

### Binary Tree:
- เป็นต้นไม้ที่แต่ละโหนดมีลูกได้ไม่เกิน 2 โหนด คือ โหนดซ้าย (Left Child) และโหนดขวา (Right Child).
- โครงสร้างนี้ทำให้การค้นหาหรือการทำงานกับข้อมูลง่ายขึ้นเพราะมีลำดับชั้นชัดเจน.

### Binary Search Tree (BST):
- เป็นต้นไม้ค้นหาแบบทวิภาค โดยข้อมูลที่น้อยกว่าจะถูกวางไว้ทางด้านซ้ายของโหนดปัจจุบัน ส่วนข้อมูลที่มากกว่าจะอยู่ทางด้านขวา.
- ประสิทธิภาพในการค้นหา แทรก หรือ ลบข้อมูลคือ O(log n) ในกรณีทั่วไป แต่ในกรณีที่ต้นไม้ไม่สมดุลจะทำให้ประสิทธิภาพลดลงไปเป็น O(n).

### AVL Tree:
- AVL Tree เป็น Binary Search Tree ที่ปรับสมดุลต้นไม้อัตโนมัติหลังจากมีการแทรกหรือลบโหนดใหม่.
- โครงสร้างของ AVL Tree มีการคำนวณ Balance Factor ซึ่งเป็นค่าต่างระหว่างความสูงของโหนดซ้ายและขวา โดยค่าที่อนุญาตคือ -1, 0, และ 1.
- เมื่อ Balance Factor เกินค่าที่กำหนด เช่น -2 หรือ 2 จะทำให้ต้นไม้ไม่สมดุล จึงต้องทำการหมุน (Rotation) เพื่อปรับสมดุล.

#### การหมุน (Rotations) ใน AVL Tree:
- Left Rotation: ใช้เมื่อต้นไม้หนักทางด้านขวา (Balance Factor < -1).
- Right Rotation: ใช้เมื่อต้นไม้หนักทางด้านซ้าย (Balance Factor > 1).
- Left-Right Rotation: ใช้เมื่อต้นไม้หนักทางซ้ายของลูกโหนดซ้าย (สองระดับ).
- Right-Left Rotation: ใช้เมื่อต้นไม้หนักทางขวาของลูกโหนดขวา (สองระดับ).

### วิธีการ Traversal:
- Inorder Traversal: เรียงลำดับข้อมูลจากน้อยไปมาก โดยเรียงจากซ้าย ราก ขวา (Left-Root-Right).
- Preorder Traversal: เรียงลำดับโดยเริ่มจากรากก่อน ตามด้วยซ้ายและขวา (Root-Left-Right).
- Postorder Traversal: เรียงลำดับจากซ้ายไปขวาแล้วจบที่ราก (Left-Right-Root).

### การใช้งาน:
- Insertion: การเพิ่มข้อมูลใหม่ลงในต้นไม้ทำได้รวดเร็วและมีประสิทธิภาพ.
- Search: ค้นหาข้อมูลใน BST หรือ AVL Tree ทำได้อย่างมีประสิทธิภาพเนื่องจากโครงสร้างแบบทวิภาค.
- Deletion: การลบข้อมูลสามารถทำได้โดยไม่สูญเสียความสมดุลในต้นไม้, โดยเฉพาะใน AVL Tree ที่มีการหมุนเพื่อรักษาสมดุล.
