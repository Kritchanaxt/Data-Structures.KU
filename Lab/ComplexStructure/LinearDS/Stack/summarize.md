
# Stack in C
- *stack* เป็นข้อมูลเชิงเส้นที่เป็นไปตามหลักการ LIFO (เข้าครั้งสุดท้าย ออกก่อน) ซึ่งหมายความว่าองค์ประกอบสุดท้ายที่เพิ่มลงในสแต็กจะเป็นองค์ประกอบแรกที่จะถูกลบออก

# Basic Stack Operations:
- **Push:** Add an element to the top of the stack.
- **Pop:** Remove the element from the top of the stack.
- **Peek:** Look at the element at the top of the stack without removing it.
- **isEmpty:** Check if the stack is empty.
- **isFull:** Check if the stack is full (in the case of a fixed-size stack).

# Summary
1. *Stack แบบใช้ Array* 
   - ใช้ array ขนาดคงที่ เหมาะสำหรับกรณีที่ขนาดของ stack ไม่เปลี่ยนแปลงบ่อย แต่ไม่ยืดหยุ่นในเรื่องขนาด
  
2. *Stack แบบใช้ Linked List*
   - ใช้โหนดที่สามารถเปลี่ยนแปลงได้ มีความยืดหยุ่นมากกว่า แต่ต้องการหน่วยความจำเพิ่มเติมเพราะมีการจัดการพ้อยเตอร์
  
3. *Stack แบบใช้ Dynamic Array*
   - ใช้การจัดสรรหน่วยความจำแบบไดนามิก ทำให้สามารถปรับขนาด stack ได้ตามความต้องการ มีความซับซ้อนมากขึ้น แต่มีความยืดหยุ่นและมีประสิทธิภาพในการจัดการขนาดที่เปลี่ยนแปลงได้