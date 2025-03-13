document.getElementById('saveBtn').addEventListener('click', () => {
    const tasks = document.querySelectorAll('.task');
    let taskData = {};
    
    
    tasks.forEach(task => {
        taskData[task.parentElement.getAttribute('data-time')] = task.value;
    });

    const selectedDate = document.getElementById('styled-date').value;
    localStorage.setItem('selectedDate', selectedDate);
    
    localStorage.setItem('tasks', JSON.stringify(taskData));
    alert('Plan Saved!');
});

document.getElementById('clearBtn').addEventListener('click', () => {
    localStorage.removeItem('tasks');
    localStorage.removeItem('selectedDate');

    document.querySelectorAll('.task').forEach(task => task.value = '');
 
    document.getElementById('styled-date').value = '';

    alert('Plan Cleared!');
});

window.onload = () => {
    const savedTasks = JSON.parse(localStorage.getItem('tasks')) || {};
    const savedDate = localStorage.getItem('selectedDate');

    document.querySelectorAll('.task').forEach(task => {
        const time = task.parentElement.getAttribute('data-time');
        if (savedTasks[time]) task.value = savedTasks[time];
    });
    if (savedDate) {
        document.getElementById('styled-date').value = savedDate;
    }
};

document.querySelectorAll('.emoji').forEach(emoji => {
    emoji.addEventListener('click', () => {
        document.querySelectorAll('.emoji').forEach(e => e.classList.remove('selected'));
        emoji.classList.add('selected');
    });
});
