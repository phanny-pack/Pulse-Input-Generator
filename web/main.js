function submitInput() {
    var data1 = document.getElementById("pulseWidth").value
    var data2 = document.getElementById("gapWidth").value
    var data3 = document.getElementById("pulseSetWidth").value
    eel.submit_input(data1,data2,data3)(function(ret) {console.log(ret)})
}