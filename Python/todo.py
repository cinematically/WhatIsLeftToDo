# // To Do List Python //
# // Creation Date 07/21/2024 //
class Task:
    def __init__(self, name, completed=False, id=None):
        self.name = name
        self.completed = completed
        self.id = id

class TodoList:
    def __init__(self):
        self.tasks = []
        self.size = 0

    def add_task(self):
        task_name = input("Enter task name: ")
        task = Task(task_name, id=self.size + 1)
        self.tasks.append(task)
        self.size += 1

    def remove_task(self, id):
        for i, task in enumerate(self.tasks):
            if task.id == id:
                del self.tasks[i]
                self.size -= 1
                print(f"Task with ID {id} removed successfully!")
                return
        print(f"Task with ID {id} not found!")

    def complete_task(self, id):
        for task in self.tasks:
            if task.id == id:
                task.completed = True
                print(f"Task with ID {id} marked as completed!")
                return
        print(f"Task with ID {id} not found!")

    def display_tasks(self):
        for task in self.tasks:
            status = "[completed]" if task.completed else ""
            print(f"{task.id}. {task.name} {status}")

def main():
    todo_list = TodoList()

    while True:
        print("Options:")
        print("1. Add task")
        print("2. Remove task")
        print("3. Complete task")
        print("4. Display tasks")
        print("5. Quit")

        choice = int(input("Choose an option: "))

        if choice == 1:
            todo_list.add_task()
        elif choice == 2:
            id = int(input("Enter task ID: "))
            todo_list.remove_task(id)
        elif choice == 3:
            id = int(input("Enter task ID: "))
            todo_list.complete_task(id)
        elif choice == 4:
            todo_list.display_tasks()
        elif choice == 5:
            break
        else:
            print("Invalid choice. Please choose a valid option.")

if __name__ == "__main__":
    main()