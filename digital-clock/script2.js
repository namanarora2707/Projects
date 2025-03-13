function updateClock() {
    let now = new Date();
    let hrs = now.getHours();
    let mins = now.getMinutes();
    let secs = now.getSeconds();
    let ampm = hrs >= 12 ? "PM" : "AM";
    hrs = hrs % 12 || 12;
    document.getElementById("hrs").innerText = String(hrs).padStart(2, "0");
    document.getElementById("mins").innerText = String(mins).padStart(2, "0");
    document.getElementById("secs").innerText = String(secs).padStart(2, "0");
    document.getElementById("ampm").innerText = ampm;
    let hh = document.getElementById("hh");
    let mm = document.getElementById("mm");
    let ss = document.getElementById("ss");
    hh.style.strokeDashoffset = 1070 - (1070 * hrs) / 12;
    mm.style.strokeDashoffset = 1070 - (1070 * mins) / 60;
    ss.style.strokeDashoffset = 1070 - (1070 * secs) / 60;
    let timeElements = document.querySelectorAll(".circle p");
    timeElements.forEach((el) => {
        el.style.animation = "none";
        setTimeout(() => el.style.animation = "pulse 1s infinite alternate, float 3s infinite ease-in-out", 50);
    });
}
setInterval(updateClock, 1000);
updateClock();