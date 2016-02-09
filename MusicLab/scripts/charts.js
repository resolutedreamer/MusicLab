// Load the Visualization API and the corechart package.
google.charts.load('current', { 'packages': ['corechart'] });

// Set a callback to run when the Google Visualization API is loaded.
//google.charts.setOnLoadCallback(drawChart);
google.charts.setOnLoadCallback(draw_volume_chart);

google.charts.setOnLoadCallback(draw_motor_pause_chart);
google.charts.setOnLoadCallback(draw_glass_distance_chart);
google.charts.setOnLoadCallback(draw_light_lux_chart);
google.charts.setOnLoadCallback(draw_system_start_chart);
google.charts.setOnLoadCallback(draw_system_pause_chart);
google.charts.setOnLoadCallback(draw_track_number_chart);


// Callback that creates and populates a data table,
// instantiates the pie chart, passes in the data and
// draws it.
function drawChart() {


    // Create the data table.
    var data = new google.visualization.DataTable();
    data.addColumn('string', 'Topping');
    data.addColumn('number', 'Slices');
    data.addRows([
      ['Mushrooms', 3],
      ['Onions', 1],
      ['Olives', 1],
      ['Zucchini', 1],
      ['Pepperoni', 2]
    ]);

    // Set chart options
    var options = {
        'title': 'How Much Pizza I Ate Last Night',
        'width': 400,
        'height': 300
    };

    // Instantiate and draw our chart, passing in some options.
    var chart = new google.visualization.BarChart(document.getElementById('chart_div'));
    chart.draw(data, options);
}

function draw_volume_chart() {

    get_sensor_data(function (output) {
        // here you use the output
        var volume_data = output[0];

        // Create the data table.
        var data = new google.visualization.DataTable();
        data.addColumn('number', 'X');
        data.addColumn('number', 'Volume');
        for (i = 0; i < 322; i++) {
            data.addRows([
                [i, volume_data[i]]
            ]);
        }

        // Set chart options
        var options = {
            'title': 'Volume',
            'width': 400,
            'height': 300
        };

        // Instantiate and draw our chart, passing in some options.
        var chart = new google.visualization.LineChart(document.getElementById('volume_chart_div'));
        chart.draw(data, options);
    });



}



function draw_motor_pause_chart() {

    get_sensor_data(function (output) {
        var motor_data = output[4];

        // Create the data table.
        var data = new google.visualization.DataTable();
        data.addColumn('number', 'X');
        data.addColumn('number', 'Motor Pause');

        for (i = 0; i < 322; i++) {
            data.addRows([
                [i, motor_data[i]]
            ]);
        }

        // Set chart options
        var options = {
            'title': 'Motor Pause',
            'width': 400,
            'height': 300
        };

        // Instantiate and draw our chart, passing in some options.
        var chart = new google.visualization.LineChart(document.getElementById('motor_pause_chart_div'));
        chart.draw(data, options);
    });
}



function draw_glass_distance_chart() {

    get_sensor_data(function (output) {
        // here you use the output
        var volume_data = output[6];

        // Create the data table.
        var data = new google.visualization.DataTable();
        data.addColumn('number', 'X');
        data.addColumn('number', 'Glass Distance');
        for (i = 0; i < 322; i++) {
            data.addRows([
                [i, volume_data[i]]
            ]);
        }

        // Set chart options
        var options = {
            'title': 'Glass Distance',
            'width': 400,
            'height': 300
        };

        // Instantiate and draw our chart, passing in some options.
        var chart = new google.visualization.LineChart(document.getElementById('glass_distance_chart_div'));
        chart.draw(data, options);
    });


}



function draw_light_lux_chart() {

    get_sensor_data(function (output) {
        // here you use the output
        var volume_data = output[5];

        // Create the data table.
        var data = new google.visualization.DataTable();
        data.addColumn('number', 'X');
        data.addColumn('number', 'Light Lux');
        for (i = 0; i < 322; i++) {
            data.addRows([
                [i, volume_data[i]]
            ]);
        }

        // Set chart options
        var options = {
            'title': 'Light Lux',
            'width': 400,
            'height': 300
        };

        // Instantiate and draw our chart, passing in some options.
        var chart = new google.visualization.LineChart(document.getElementById('light_lux_chart_div'));
        chart.draw(data, options);
    });

}



function draw_system_start_chart() {

    get_sensor_data(function (output) {
        // here you use the output
        var volume_data = output[2];

        // Create the data table.
        var data = new google.visualization.DataTable();
        data.addColumn('number', 'X');
        data.addColumn('number', 'System Start');
        for (i = 0; i < 322; i++) {
            data.addRows([
                [i, volume_data[i]]
            ]);
        }

        // Set chart options
        var options = {
            'title': 'System Start',
            'width': 400,
            'height': 300
        };

        // Instantiate and draw our chart, passing in some options.
        var chart = new google.visualization.LineChart(document.getElementById('system_start_chart_div'));
        chart.draw(data, options);
    });

}



function draw_system_pause_chart() {

    get_sensor_data(function (output) {
        // here you use the output
        var volume_data = output[3];

        // Create the data table.
        var data = new google.visualization.DataTable();
        data.addColumn('number', 'X');
        data.addColumn('number', 'System Pause');
        for (i = 0; i < 322; i++) {
            data.addRows([
                [i, volume_data[i]]
            ]);
        }

        // Set chart options
        var options = {
            'title': 'System Pause',
            'width': 400,
            'height': 300
        };

        // Instantiate and draw our chart, passing in some options.
        var chart = new google.visualization.LineChart(document.getElementById('system_pause_chart_div'));
        chart.draw(data, options);
    });

}



function draw_track_number_chart() {


    get_sensor_data(function (output) {
        // here you use the output
        var volume_data = output[1];

        // Create the data table.
        var data = new google.visualization.DataTable();
        data.addColumn('number', 'X');
        data.addColumn('number', 'Track Number');
        for (i = 0; i < 322; i++) {
            data.addRows([
                [i, volume_data[i]]
            ]);
        }

        // Set chart options
        var options = {
            'title': 'Track Number',
            'width': 400,
            'height': 300
        };

        // Instantiate and draw our chart, passing in some options.
        var chart = new google.visualization.LineChart(document.getElementById('track_number_chart_div'));
        chart.draw(data, options);
    });

}

