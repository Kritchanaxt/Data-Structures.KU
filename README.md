# Data Structures in C 
- **Data Structures** คือ วิธีการจัดเก็บและจัดการข้อมูลในคอมพิวเตอร์เพื่อให้สามารถเข้าถึงและแก้ไขข้อมูลได้อย่างมีประสิทธิภาพ ตัวอย่างของโครงสร้างข้อมูล ได้แก่ อาร์เรย์, ลิงก์ลิสต์, สแตก, คิว, และต้นไม้

### Array และ Linked List
- เป็นโครงสร้างข้อมูลพื้นฐาน (basic data structures) ที่ใช้ในการจัดเก็บข้อมูล เป็นลำดับ (sequential)
   - Array ใช้การจัดเก็บข้อมูลในหน่วยความจำที่ต่อเนื่อง
   - Linked List ใช้ โหนด (nodes) ที่เชื่อมโยงกันผ่าน ตัวชี้ (pointers).

### Stack, Queue, Tree, และ Graph
-เป็นโครงสร้างข้อมูลขั้นสูง (advanced data structures) ที่ถูกสร้างขึ้นจากการใช้ Array หรือ Linked List
  - Stack: สร้างขึ้นจาก Array หรือ Linked List โดยใช้หลักการ LIFO (Last In, First Out).
  - Queue: ใช้หลักการ FIFO (First In, First Out).
  - Tree: เป็นโครงสร้างแบบลำดับชั้น (hierarchical) ที่ใช้โหนดและตัวชี้ในการสร้างความสัมพันธ์ระหว่างข้อมูล.
  - Graph: เป็นโครงสร้างที่ซับซ้อนกว่า โดยโหนดจะเชื่อมกันด้วยเส้นเชื่อม (edges) ซึ่งอาจสร้างจาก Array หรือ Linked List.

### สรุปง่ายๆ
- Array และ Linked List เป็นโครงสร้างพื้นฐาน.
- Stack, Queue, Tree, และ Graph เป็นโครงสร้างที่ซับซ้อนกว่า ซึ่งสามารถสร้างขึ้นจาก Array หรือ Linked List.

## Array ⚙️
- **Array** เป็นโครงสร้างข้อมูลพื้นฐานในภาษา C ที่ใช้ในการจัดเก็บชุดของข้อมูลประเภทเดียวกันในตำแหน่งที่ต่อเนื่องกันในหน่วยความจำ โดยการเข้าถึงข้อมูลในอาเรย์สามารถทำได้โดยใช้ดัชนี (index)

<img width="1000" alt="Array1" src="https://github.com/user-attachments/assets/21e2ec50-7ebc-4384-8e31-9910f5834381">  

### การประกาศ Array 
```
data_type array_name[array_size];
```
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
  
## Node 🪀
- **Node** เป็นหน่วยพื้นฐานที่ใช้ในการจัดเก็บข้อมูลและเชื่อมโยงไปยังโหนดอื่นๆ 

<img width="1000" alt="Node" src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRJ5F4EBEjzdiJ5sNTIuvsjiz1lCJVj2Q-vMA&s">  

### Node แต่ละตัวมีสองส่วนหลัก
- **Data (ข้อมูล):** ใช้ในการจัดเก็บข้อมูลที่เราต้องการ เช่น ตัวเลข ข้อความ หรือข้อมูลประเภทอื่น
- **Pointer (ตัวชี้):** ใช้ในการเชื่อมโยงโหนดปัจจุบันไปยังโหนดถัดไปในลิสต์ (หรือโหนดก่อนหน้าในกรณีของลิงก์ลิสต์แบบสองทิศทาง)
  
### การใช้งานของ Node 
- โหนดเป็นหน่วยที่เชื่อมต่อกันในลิงก์ลิสต์โดยการอ้างอิงถึงกัน ทำให้สามารถสร้างลิสต์ที่มีขนาดแตกต่างกันตามความต้องการของโปรแกรม

## Linked List 🔗
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

## Stack 🔋
- **Stack** คือโครงสร้างข้อมูลเชิงเส้นที่ทำงานตามหลักการ Last In, First Out (LIFO) หมายความว่าองค์ประกอบที่ถูกเพิ่มเข้ามาเป็นองค์ประกอบสุดท้ายจะถูกนำออกเป็นองค์ประกอบแรก สามารถนึกภาพได้ว่าเหมือนกับกองจานที่เราสามารถเพิ่มหรือเอาจานออกจากด้านบนสุดเท่านั้น

<img width="600" alt="Stack1" src="https://github.com/user-attachments/assets/7824c5ec-c513-465b-8129-2a7cecc7eaa4"> 

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

## Queue 💉
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

<img width="600"  alt="Queue2" src="https://github.com/user-attachments/assets/a6bf85d8-2f0f-4713-8d0e-bc5edcc856e9">

### กรณีการใช้งาน Queue
- **การจัดการคิวของงาน:** ในระบบปฏิบัติการ การจัดการกับงานที่ต้องทำให้เสร็จตามลำดับ
- **การจัดการกับการพิมพ์:** ในระบบที่มีการพิมพ์เอกสารจากหลายแหล่ง ข้อมูลของเอกสารจะถูกจัดเก็บในคิว
- **การจัดการกับการสื่อสารข้อมูล:** การส่งข้อมูลผ่านเครือข่าย ที่ข้อมูลจะถูกจัดเก็บในคิวก่อนการส่งต่อไปยังปลายทาง
- **การจัดการเหตุการณ์ในเกม:** การจัดการกับเหตุการณ์ที่เกิดขึ้นในเกมตามลำดับ

## Trees 🌳

- **Trees** คือโครงสร้างข้อมูลชนิดหนึ่งที่เป็นแบบลำดับชั้น (hierarchical) 
โดยมีการเชื่อมโยงกันเป็นลำดับของโหนด (nodes) ซึ่งต้นไม้ (Tree) เป็นโครงสร้างข้อมูลที่ใช้อย่างแพร่หลายในการจัดการข้อมูลเชิงลำดับที่ซับซ้อน เช่น โครงสร้างแฟ้มข้อมูล โครงสร้างของเว็บไซต์ หรือการจัดการฐานข้อมูล.

### โครงสร้างข้อมูลแบบลำดับชั้น (Hierarchical Structure)
- โครงสร้างข้อมูลแบบลำดับชั้นจัดเก็บข้อมูลเป็นลำดับชั้น มีการเชื่อมโยงกันระหว่างโหนด (Node).
- โหนดมีโหนดราก (Root Node) เป็นโหนดเริ่มต้น และมีลูกโหนด (Child Nodes) เป็นโหนดย่อยที่เชื่อมต่อกันในรูปแบบต้นไม้.

![Treedatastructure](https://github.com/user-attachments/assets/23c5fa76-00fe-41b4-959b-72b3c52d6d46)
  
#### องค์ประกอบของ Trees:
- Root (ราก): โหนดเริ่มต้นของต้นไม้ ซึ่งไม่มีโหนดพ่อแม่ (parent node).
- Node (โหนด): แต่ละจุดในต้นไม้ที่สามารถเก็บข้อมูล และมีการเชื่อมโยงกับโหนดลูก (child nodes).
- Edge (ขอบ): เส้นทางที่เชื่อมโยงโหนดหนึ่งไปยังอีกโหนดหนึ่ง.
- Parent (พ่อแม่): โหนดที่มีโหนดอื่นเป็นลูก.
- Child (ลูก): โหนดที่เป็นลูกของโหนดอื่น.
- Leaf (ใบ): โหนดที่ไม่มีลูก หรือเป็นโหนดปลายของต้นไม้.
- Subtree (ต้นไม้ย่อย): ต้นไม้ที่เกิดจากโหนดย่อยในต้นไม้หลัก.

### Binary Tree:
<img width="1000" alt="BT" src="https://github.com/user-attachments/assets/d50f25a1-c57f-426f-9c5d-f025d0c12bae">  

- เป็นต้นไม้ที่แต่ละโหนดมีลูกได้ไม่เกิน 2 โหนด คือ โหนดซ้าย (Left Child) และโหนดขวา (Right Child).
- โครงสร้างนี้ทำให้การค้นหาหรือการทำงานกับข้อมูลง่ายขึ้นเพราะมีลำดับชั้นชัดเจน.

### Binary Search Tree (BST):

<img width="1000" alt="BST" src="https://skilled.dev/images/bst-visualize.gif">  

- เป็นต้นไม้ค้นหาแบบทวิภาค โดยข้อมูลที่น้อยกว่าจะถูกวางไว้ทางด้านซ้ายของโหนดปัจจุบัน ส่วนข้อมูลที่มากกว่าจะอยู่ทางด้านขวา.

### AVL Tree:
![avl-tree](https://github.com/user-attachments/assets/a1b4e587-8d87-4355-ac6c-11421a718296)
<img width="924" alt="avl-tree_balnce2" src="https://github.com/user-attachments/assets/4ac19511-b95b-4d1c-b135-55341e5d6141">


- AVL Tree เป็น Binary Search Tree ที่ปรับสมดุลต้นไม้อัตโนมัติหลังจากมีการแทรกหรือลบโหนดใหม่.
- โครงสร้างของ AVL Tree มีการคำนวณ Balance Factor ซึ่งเป็นค่าต่างระหว่างความสูงของโหนดซ้ายและขวา โดยค่าที่อนุญาตคือ -1, 0, และ 1.
- เมื่อ Balance Factor เกินค่าที่กำหนด เช่น -2 หรือ 2 จะทำให้ต้นไม้ไม่สมดุล จึงต้องทำการหมุน (Rotation) เพื่อปรับสมดุล.

#### การหมุน (Rotations) ใน AVL Tree:

<img width="500" alt="Rotations" src="https://upload.wikimedia.org/wikipedia/commons/3/31/Tree_rotation_animation_250x250.gif">  

- Left Rotation: ใช้เมื่อต้นไม้หนักทางด้านขวา (Balance Factor < -1).
- Right Rotation: ใช้เมื่อต้นไม้หนักทางด้านซ้าย (Balance Factor > 1).
- Left-Right Rotation: ใช้เมื่อต้นไม้หนักทางซ้ายของลูกโหนดซ้าย (สองระดับ).
- Right-Left Rotation: ใช้เมื่อต้นไม้หนักทางขวาของลูกโหนดขวา (สองระดับ).

### วิธีการ Traversal:

1. Inorder Traversal: เรียงลำดับข้อมูลจากน้อยไปมาก โดยเรียงจากซ้าย ราก ขวา (Left-Root-Right).
<img width="600" alt="Inorder" src="https://miro.medium.com/v2/resize:fit:960/format:webp/1*nvZSw3M2Uq3EXOsc8Kd2Sw.gif">  

2. Preorder Traversal: เรียงลำดับโดยเริ่มจากรากก่อน ตามด้วยซ้ายและขวา (Root-Left-Right).
<img width="600" alt="Preorder" src="https://miro.medium.com/v2/resize:fit:960/1*Swjb2CWGQh55r9m7jEyg1Q.gif"> 

3. Postorder Traversal: เรียงลำดับจากซ้ายไปขวาแล้วจบที่ราก (Left-Right-Root).
<img width="600" alt="Postorder" src="https://miro.medium.com/v2/resize:fit:960/format:webp/1*4KpXD6en9pbN2mgbq4XraA.gif"> 

### การใช้งาน:
- Insertion: การเพิ่มข้อมูลใหม่ลงในต้นไม้ทำได้รวดเร็วและมีประสิทธิภาพ.
- Search: ค้นหาข้อมูลใน BST หรือ AVL Tree ทำได้อย่างมีประสิทธิภาพเนื่องจากโครงสร้างแบบทวิภาค.
- Deletion: การลบข้อมูลสามารถทำได้โดยไม่สูญเสียความสมดุลในต้นไม้, โดยเฉพาะใน AVL Tree ที่มีการหมุนเพื่อรักษาสมดุล.

## Graphs 📈

- **กราฟ (Graphs)** เป็นโครงสร้างข้อมูลที่ประกอบด้วยชุดของโหนด (vertices) และเส้นเชื่อมระหว่างโหนด (edges) ซึ่งใช้ในการแทนความสัมพันธ์ต่างๆ ในการประมวลผลข้อมูล

  
<img width="500" alt="Screenshot 2567-09-19 at 16 26 27" src="https://github.com/user-attachments/assets/fa8c1871-8cc8-4dce-be6f-8ad97d78d91e"><img width="500" alt="Screenshot 2567-09-19 at 16 26 37" src="https://github.com/user-attachments/assets/9e40f798-de54-47c5-9a9d-227737b5835c">



### 1. กราฟแบบมีทิศทาง (Directed Graph) และกราฟแบบไม่มีทิศทาง (Undirected Graph)
- กราฟแบบมีทิศทาง (Directed Graph หรือ Digraph): เส้นเชื่อม (edges) ระหว่างโหนดจะมีทิศทาง กล่าวคือมีการระบุทิศทางการเชื่อมจากโหนดหนึ่งไปยังอีกโหนดหนึ่ง ตัวอย่างเช่นในกราฟของโซเชียลมีเดีย ผู้ใช้ A ติดตามผู้ใช้ B แต่ B อาจจะไม่ได้ติดตาม A กลับ
- กราฟแบบไม่มีทิศทาง (Undirected Graph): เส้นเชื่อมระหว่างโหนดไม่มีทิศทาง กล่าวคือสามารถเดินทางจากโหนด A ไปยังโหนด B หรือจาก B ไปยัง A ได้ทั้งสองทิศทาง ตัวอย่างเช่นในกราฟของเพื่อน คน A และคน B เป็นเพื่อนกันจึงเชื่อมต่อกันในทั้งสองทิศทาง

### 2. กราฟแบบมีน้ำหนัก (Weighted Graph) และกราฟแบบไม่มีน้ำหนัก (Unweighted Graph)
- กราฟแบบมีน้ำหนัก (Weighted Graph): แต่ละเส้นเชื่อม (edges) จะมีค่าน้ำหนักที่แตกต่างกัน เช่น ค่าความห่างไกล ค่าใช้จ่าย หรือเวลาในการเดินทางตัวอย่าง เช่น กราฟของเครือข่ายถนนที่เชื่อมระหว่างเมืองต่างๆที่มีระยะทางเป็นน้ำหนักของแต่ละเส้นเชื่อม
- กราฟแบบไม่มีน้ำหนัก (Unweighted Graph): ไม่มีค่าน้ำหนักบนเส้นเชื่อม เส้นเชื่อมจะมีค่าเท่ากันทั้งหมด

### 3. การแทนกราฟ (Graph Representation)
***กราฟสามารถแทนได้หลายวิธี***
- Adjacency Matrix: เป็นเมทริกซ์สองมิติที่แสดงความสัมพันธ์ระหว่างโหนด ถ้าโหนด i และ j มีเส้นเชื่อม เมทริกซ์จะมีค่าเป็น 1 (หรือเป็นค่าน้ำหนักในกรณีของกราฟแบบมีน้ำหนัก) ถ้าไม่มีเส้นเชื่อมจะเป็น 0
- Adjacency List: เป็นลิสต์ที่เก็บลิสต์ของโหนดที่เชื่อมต่อกัน ซึ่งมีประสิทธิภาพมากกว่าสำหรับกราฟขนาดใหญ่

### 4. การค้นหากราฟ (Graph Traversal)
***การเดินผ่านโหนดในกราฟสามารถทำได้สองวิธีหลัก***
- Breadth-First Search (BFS): การค้นหาแบบกว้าง จะเริ่มต้นจากโหนดหนึ่งและสำรวจโหนดทั้งหมดที่อยู่ใกล้เคียงก่อน แล้วจึงขยายไปยังโหนดที่อยู่ไกลขึ้น
- Depth-First Search (DFS): การค้นหาแบบลึก จะสำรวจเส้นทางจากโหนดหนึ่งไปจนสุดทางแล้วย้อนกลับมาตรวจสอบเส้นทางที่ยังไม่ได้สำรวจ

### 5. ประเภทกราฟ (Graph Types)
- Cyclic Graph: กราฟที่มีเส้นเชื่อมวนรอบกลับมาที่โหนดเริ่มต้น
- Acyclic Graph: กราฟที่ไม่มีวงรอบ
- Connected Graph: กราฟที่ทุกโหนดสามารถเชื่อมต่อกันได้
- Disconnected Graph: กราฟที่มีโหนดบางโหนดที่ไม่สามารถเชื่อมถึงกันได้

## Graphs II 📉


### Minimum Spanning Trees (MST)
***Minimum Spanning Tree (MST) คือ กราฟต้นไม้ (Tree) ที่เป็นส่วนน้อยที่สุดของกราฟที่เชื่อมต่อกัน ซึ่งมีผลรวมของน้ำหนักเส้นเชื่อม (Edge Weight) ต่ำที่สุด โดย MST ต้องประกอบไปด้วย:***
1. ไม่มีวงจร (Cycle)
2. เชื่อมต่อกันทุกจุด (Connected)
3. ใช้เส้นเชื่อม (Edges) ที่มีน้ำหนักรวมต่ำที่สุด
4. MST มีประโยชน์ในการแก้ปัญหาต่างๆ เช่นการออกแบบเครือข่ายที่มีค่าใช้จ่ายต่ำที่สุด

### Prim's Algorithm (อัลกอริทึมของพริม)
***Prim's Algorithm ใช้สำหรับหาต้นไม้ที่ครอบคลุมทั้งหมด (Minimum Spanning Tree) โดยอัลกอริทึมนี้จะเริ่มต้นจากจุดยอด (Vertex) จุดหนึ่ง แล้วค่อยๆ ขยายไปยังจุดยอดข้างเคียงที่มีน้ำหนักเส้นเชื่อมต่ำที่สุดจนกว่าจะครอบคลุมทุกจุดยอดในกราฟ***

**ขั้นตอน:**
1. เริ่มจากจุดยอดใดก็ได้ในกราฟ
2. เลือกเส้นเชื่อมที่มีน้ำหนักน้อยที่สุดจากจุดที่เยี่ยมชมแล้วไปยังจุดยอดที่ยังไม่ได้เยี่ยมชม
3. ทำซ้ำจนกระทั่งทุกจุดยอดถูกเยี่ยมชม


### Kruskal's Algorithm (อัลกอริทึมของครัสคาล)
***Kruskal's Algorithm ใช้สำหรับหาต้นไม้ที่ครอบคลุมทั้งหมด (Minimum Spanning Tree) โดยการจัดลำดับเส้นเชื่อม (Edges) จากน้ำหนักน้อยที่สุดไปมากที่สุด และค่อยๆ เพิ่มเส้นเชื่อมที่ไม่มีวงจร (Cycle) จนกว่าจะสร้างต้นไม้ที่เชื่อมต่อทุกจุดยอด***

**ขั้นตอน:**
1. จัดลำดับเส้นเชื่อมตามน้ำหนักจากน้อยไปมาก
2. เริ่มจากเส้นเชื่อมที่น้ำหนักน้อยที่สุด
3. เพิ่มเส้นเชื่อมตราบใดที่ไม่ทำให้เกิดวงจร
4. ทำซ้ำจนกระทั่งเชื่อมต่อครบทุกจุดยอด

### Dijkstra's Algorithm (อัลกอริทึมของไดจ์กสตรา)
***Dijkstra's Algorithm ใช้สำหรับการหาทางที่สั้นที่สุดจากจุดต้นทางไปยังทุกจุดในกราฟที่มีน้ำหนักบวก (Positive Weights)***

**ขั้นตอน:**
1. เริ่มจากจุดยอดต้นทาง
2. กำหนดระยะทางของจุดยอดต้นทางเป็น 0 และจุดยอดอื่นๆ เป็น ∞ (Infinity)
3. เลือกจุดยอดที่ยังไม่เยี่ยมชมและมีระยะทางน้อยที่สุด
4. ปรับปรุงระยะทางของจุดยอดข้างเคียงของจุดยอดนั้นๆ หากระยะทางสั้นกว่า
5. ทำซ้ำจนกระทั่งเยี่ยมชมครบทุกจุดยอด

# Algorithm (อัลกอริทึม)
- ความหมาย: เป็นลำดับของขั้นตอนการทำงานที่ชัดเจนและจำกัด เพื่อแก้ปัญหาหรือทำงานบางอย่าง โดยอัลกอริทึมจะระบุขั้นตอนทั้งหมดที่จำเป็นต้องทำเพื่อให้ได้ผลลัพธ์ที่ต้องการ

- คุณสมบัติ:
มีจุดเริ่มต้นและจุดสิ้นสุดที่ชัดเจน
ลำดับขั้นตอนถูกกำหนดไว้อย่างเฉพาะเจาะจง
สามารถนำไปใช้ซ้ำได้

- ตัวอย่าง: อัลกอริทึมสำหรับการจัดเรียงข้อมูล (เช่น Bubble Sort, Quick Sort) หรือการค้นหาข้อมูล (เช่น Binary Search, Linear Search)

## Searching 🔍
### 1. Linear Search (การค้นหาเชิงเส้น):
- เป็นวิธีการค้นหาที่ง่ายที่สุด โดยตรวจสอบแต่ละองค์ประกอบในลิสต์หรืออาเรย์ทีละตัวจนกว่าจะพบค่าที่ต้องการ
  
#### Concept
- เหมือนการที่เราเดินถามไปที่ละคน จนกว่าจะเจอคนที่ต้องการ

### 2. Binary Search (การค้นหาแบบทวิภาค):
- ใช้สำหรับค้นหาตัวเลขในอาร์เรย์ที่เรียงลำดับแล้ว โดยแบ่งครึ่งอาร์เรย์และเปรียบเทียบค่ากับค่ากลาง (mid) ในทุกครั้ง

#### Concept
- Array [0,1,2,3,4,5,6,7,8,9,10]
- Val = 9, BEG = 0, END = 10, Mid = (BEG + END) / 2, A[Mid] = ?
- เหมือนแบบอยากหาค่า 9 แล้วหาค่า Mid ได้แล้ว 
- โดย Mid (0+10) / 2 และจะมีค่า A[Mid] = 5
- จากนั้นให้มาดูที่ 5 ว่า 9 อยู่ซ้ายหรือขวาแล้วเลือกฝั่ง เช่น ในตัวอย่าง Array ต้องเลือกฝั่งขวา
- จากนั้นก็ทำแบบเดิมจนกว่าจะได้ค่า Mid = 9 


## Sorting 📝
### 1. Bubble Sort:
- ทำงานโดยเปรียบเทียบค่าที่อยู่ติดกันและสลับตำแหน่งถ้าค่าตัวแรกมากกว่าค่าตัวหลัง ทำซ้ำจนกว่าลิสต์จะเรียงลำดับสมบูรณ์

#### Concept
- เหมือนเรียงแถวตามระดับความสูง เช่น คนที่สูงสลับกับคนที่เตี้ยกว่า

### 2. Merge Sort:
- เป็นการจัดเรียงแบบแยกและรวม (Divide and Conquer) โดยแยกข้อมูลเป็นครึ่งหนึ่งจนมีขนาดเล็กสุด แล้วค่อย ๆ รวมกลับมาโดยการจัดเรียงในแต่ละขั้นตอน
  
<img width="1264" alt="Screenshot 2567-10-10 at 14 19 35" src="https://github.com/user-attachments/assets/972945ff-4f76-4862-ba1d-42eef8fc7bce">

#### Concept
- คือ การเอา array มาต่อกัน โดยการหาค่าตรงกลางก่อน Mid = (BEG + END) / 2 เพื่อหาค่า MID 
- และ ให้  I อยู่ฝั่ง BEG, J อยู่ฝั่ง END , Array 2 = temp 
- โดยเงื่อนไข ให้ทำการเปรียบเทียบค่า โดยการนำค่าที่น้อยกว่า ไปสำเนาที่ Array 2 และไล่ไปที่ละ Index เช่น MID = 3 
- Array1[1,2,3,4,5,6] สำเนาค่าน้อยทีละตัว -> Array2[1,2,...,6]

### 3. Quick Sort:
- เป็นการจัดเรียงที่เลือก "ตัวชี้" (pivot) แล้วแยกข้อมูลเป็นสองส่วนคือค่าที่น้อยกว่าหรือมากกว่า pivot หลังจากนั้นจะจัดเรียงแต่ละส่วนแยกกัน
- left = < น้อยกว่า
- right = > มากกว่า
- log = Located อยู่กับที่ 

<img width="1192" alt="Screenshot 2567-10-10 at 14 30 58" src="https://github.com/user-attachments/assets/08fca058-cefc-4923-9502-c70cecbcf558">

#### Concept 
- ให้ left อยู่ฝั่งซ้ายสุดก็คือ 25 , right อยู่ฝั่งขวาสุดก็คือ 45
- โดยเงื่อนไข คือ เปรียบเทียบค่า ถ้ามีค่ามากให้อยู่ฝั่งขวา ถ้าค่าน้อยอยู่ฝั่งซ้าย
- โดยให้โยน loc ไปพร้อมกับตัวที่สลับ
- จังหวะสลับโยน loc มาด้วย เช่น loc, left -> loc, right

#### Things to do
1. ต้องเปรียบเทียบเพื่อหาค่า mid 
2. จะหาค่า mid โดยทำการเปรียบเทียบเรื่อยๆจนกว่า left, right, loc จะตรงกัน
2. ระเบิด array ออกมาเป็น 2 ก้อน 
3. เปรียบเทียบ ทีละก้อน หาก ยังไม่ถูกต้อง ก็ระเบิดอีกครั้ง และทำเหมือนเดิม 
เช่น 18,10,25 -> 18,10 = 10,18
4. หาผลลัพธ์จากแต่ละรอบ 

<img width="1272" alt="loc, left" src="https://github.com/user-attachments/assets/317c2a1a-b62f-4c0a-81bc-4514fb15abce">

#### ระเบิด Array
- รอบ 1 = 25,10,18,27,36,45
- รอบ 2 = 36,45
- รอบ 3 = 18,10,25
- รอบ 4 = 10, 18
- Result = 10,18,25,27,36,45

## Data Hierarchy
- ความหมาย: Data Hierarchy เป็นโครงสร้างของข้อมูลที่จัดเรียงเป็นลำดับชั้นจากระดับต่ำไปหาสูง เพื่อให้เข้าใจได้ง่ายขึ้น โดยประกอบด้วยระดับต่างๆ ดังนี้:
  - Bit: หน่วยที่เล็กที่สุดของข้อมูลในคอมพิวเตอร์ มีค่าเป็น 0 หรือ 1
  - Byte: ประกอบด้วย 8 bits ใช้แทนข้อมูลต่างๆ เช่น ตัวอักษรหนึ่งตัว
  - Field: กลุ่มของ Bytes ที่แทนข้อมูลชนิดเดียวกัน เช่น ชื่อ, อายุ
  - Record: กลุ่มของ Fields ที่เกี่ยวข้องกัน ซึ่งแทนข้อมูลทั้งหมดของหนึ่งรายการ เช่น รายละเอียดของนักเรียนหนึ่งคน
  - File: กลุ่มของ Records ที่มีลักษณะเดียวกัน เช่น ไฟล์ข้อมูลของนักเรียนทั้งหมด
  - Database: กลุ่มของ Files ที่มีการเชื่อมโยงและจัดการข้อมูลแบบรวมศูนย์

### Files
- ความหมาย: Files เป็นที่เก็บข้อมูลในคอมพิวเตอร์ โดยข้อมูลในไฟล์อาจเป็นข้อความ, ตัวเลข, รูปภาพ หรือไฟล์เสียงก็ได้ ไฟล์แต่ละไฟล์มีชื่อ (filename) และชนิด (file extension) ที่ระบุประเภทของไฟล์ เช่น .txt, .c, .jpg

### File Openings
- ความหมาย: การเปิดไฟล์ในภาษา C ทำได้โดยใช้ฟังก์ชัน fopen() ซึ่งต้องระบุโหมดในการเปิดไฟล์ เช่น:
  - "r": เปิดไฟล์สำหรับอ่าน
  - "w": เปิดไฟล์สำหรับเขียน (ข้อมูลในไฟล์เดิมจะถูกลบ)
  - "a": เปิดไฟล์สำหรับเขียนต่อจากข้อมูลเดิม
  - "r+", "w+", "a+": เปิดไฟล์สำหรับทั้งอ่านและเขียน

### File Organizations
- ความหมาย: การจัดระเบียบไฟล์ (File Organization) หมายถึงวิธีการจัดเก็บข้อมูลในไฟล์ ซึ่งมีหลายรูปแบบ เช่น:
  - Sequential File Organization: จัดเก็บข้อมูลแบบเรียงตามลำดับ ถ้าต้องการค้นหาต้องอ่านไฟล์ตั้งแต่ต้นจนพบข้อมูลที่ต้องการ
  - Direct or Random File Organization: เข้าถึงข้อมูลได้โดยตรงโดยใช้คีย์เฉพาะ เช่น การเข้าถึงข้อมูลในตำแหน่งที่ระบุ
  - Indexed File Organization: จัดเก็บข้อมูลโดยมีดัชนีช่วยในการค้นหาข้อมูลได้เร็วขึ้น

## Big O Notation 
- เป็นวิธีการใช้เพื่อวัดประสิทธิภาพของอัลกอริทึมในแง่ของเวลาในการทำงาน (Time Complexity) หรือหน่วยความจำที่ใช้ (Space Complexity) โดยจะบอกถึงการเติบโตของอัลกอริทึมเมื่อขนาดของข้อมูล (n) เพิ่มขึ้น ซึ่งจะช่วยให้สามารถประเมินได้ว่าอัลกอริทึมใดมีประสิทธิภาพมากกว่ากัน

#### ประเภทของ Big O Notation
1. O(1) - Constant Time: เวลาในการทำงานไม่เปลี่ยนแปลงตามขนาดของข้อมูล เช่น การเข้าถึงสมาชิกในอาร์เรย์โดยใช้ดัชนี

```
int getFirstElement(int arr[]) {
    return arr[0]; // O(1)
}
```

2. O(n) - Linear Time: เวลาในการทำงานเพิ่มขึ้นตามขนาดของข้อมูล เช่น การวนลูปผ่านสมาชิกในอาร์เรย์ทั้งหมด
```
void printAllElements(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); // O(n)
    }
}
```
3. O(n) - Linear Time: เวลาในการทำงานเพิ่มขึ้นตามขนาดของข้อมูล เช่น การวนลูปผ่านสมาชิกในอาร์เรย์ทั้งหมด
```
void printAllPairs(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("(%d, %d) ", arr[i], arr[j]); // O(n^2)
        }
    }
}
```
4. O(log n) - Logarithmic Time: เวลาในการทำงานเพิ่มขึ้นตามลอการิทึมของขนาดข้อมูล เช่น การค้นหาแบบ Binary Search
```
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid; // O(log n)
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Target not found
}
```
5. O(n log n) - Linearithmic Time: เวลาในการทำงานเพิ่มขึ้นเป็นเส้นตรงคูณกับลอการิทึมของขนาดข้อมูล เช่น การเรียงลำดับแบบ Merge Sort หรือ Quick Sort
```
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid); // O(n log n)
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
```
6. O(2^n) - Exponential Time: เวลาในการทำงานเพิ่มขึ้นเป็นสองเท่าของขนาดข้อมูล เช่น อัลกอริทึมที่เกี่ยวกับการคำนวณฟีโบนัชชี่แบบเรียกซ้ำ
```
int fibonacci(int n) {
    if (n <= 1) {
        return n; // O(2^n)
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```
7. O(n!) - Factorial Time: เวลาในการทำงานเพิ่มขึ้นตามแฟกทอเรียลของขนาดข้อมูล เช่น การจัดเรียงแบบ Permutation
```
void permute(char* str, int left, int right) {
    if (left == right) {
        printf("%s\n", str); // O(n!)
    } else {
        for (int i = left; i <= right; i++) {
            swap((str + left), (str + i));
            permute(str, left + 1, right);
            swap((str + left), (str + i)); // backtrack
        }
    }
}
```
#### สรุป
- Big O Notation ช่วยบอกถึงความซับซ้อนของอัลกอริทึมโดยไม่สนใจรายละเอียดของฮาร์ดแวร์หรือซอฟต์แวร์
- เลขยกกำลังสูงและแฟกทอเรียลมีการเติบโตที่รวดเร็วที่สุด และอัลกอริทึมที่ซับซ้อนควรหลีกเลี่ยง

  


