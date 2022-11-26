

class queueArray:

    def __init__(self):
        self.queue = []

    def printQueue(self):
        print(self.queue)

    def isEmpty(self):
        if not self.queue:
            return True;
        else:
            return False;

    def enqueue(self,value):
        self.queue.append(value)

    def dequeue(self):
        if self.isEmpty():
            return "큐가 비었습니다."

        else:
            result = self.queue[0]
            self.queue = self.queue[1:] # dequeue 한 값 삭제
            return result


if __name__ == '__main__':

    queue = queueArray()

    queue.enqueue(1)
    queue.printQueue()

    queue.enqueue(2)
    queue.printQueue()

    queue.enqueue(3)
    queue.printQueue()

    queue.enqueue(4)
    queue.printQueue()

    queue.enqueue(5)
    queue.printQueue()

    queue.dequeue()
    queue.printQueue()

