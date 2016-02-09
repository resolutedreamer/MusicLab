function get_actuator_data() {
    $.ajax({
        url: "https://api.mongolab.com/api/1/databases/musiclab/collections/control_play?apiKey=DjDKE7adIsCNxYsls6ItXSR67DquF-11",
        dataType: "json",
        success: function (data) {
            console.log("Data from 'control_play' collection");
            var real_data = data[0].command_value;
            if (real_data == 0) {
                console.log("Not Playing Music");
                $('#playback_control').prop('checked', false);
            }
            else if (real_data == 1) {
                console.log("Playing Music");
                $('#playback_control').prop('checked', true);
            }
        }
    })

    $.ajax({
        url: "https://api.mongolab.com/api/1/databases/musiclab/collections/music?apiKey=DjDKE7adIsCNxYsls6ItXSR67DquF-11",
        dataType: "json",
        success: function (data) {
            console.log("Data from 'music' collection");
            var real_data = data[0].track_id;
            if (real_data == 1) {
                console.log("Playing Jingle Bells");
                $('#op1').prop('selected', true);
            }
            else if (real_data == 2) {
                console.log("Playing Starcraft");
                $('#op2').prop('selected', true);
            }
            else if (real_data == 3) {
                console.log("Playing Mega Man");
                $('#op3').prop('selected', true);
            }
            else if (real_data == 4) {
                console.log("Playing Airplane");
                $('#op4').prop('selected', true);
            }
            //$("#target4").html("<i>#target4</i>");
        }
    })
};

get_actuator_data();


function get_sensor_data(handleData) {
    console.log("Entered Function get_sensor_data")
    var my_data = [];
    $.ajax({
        url: "https://api.mongolab.com/api/1/databases/musiclab/collections/sensor_data?apiKey=DjDKE7adIsCNxYsls6ItXSR67DquF-11",
        dataType: "json",
        success: function (data) {
            console.log("get_sensor_data ajax success")
            console.log("Data from 'sensor_data' collection");
            console.log("Expected 322 Sensor Values");
            console.log(data);
            console.log(data.length);
            console.log("Let's get the most recent value");
            
            var glass_distance_array = [];
            var light_lux_array = [];
            var motor_pause_array = [];
            var system_pause_array = [];
            var system_start_array = [];
            var track_number_array = [];
            var volume_array = [];

            for (i = 0; i < data.length; i++) {
                var x = data[i];
                //console.log(x);
                glass_distance_array.push(x.glass_distance);
                light_lux_array.push(x.light_lux);
                motor_pause_array.push(x.motor_pause);
                system_pause_array.push(x.system_pause);
                system_start_array.push(x.system_start);
                track_number_array.push(x.track_number);
                volume_array.push(x.volume);
            }

            console.log(glass_distance_array);
            console.log(light_lux_array);
            console.log(motor_pause_array);
            console.log(system_pause_array);
            console.log(system_start_array);
            console.log(track_number_array);
            console.log(volume_array);
            
            /*
            my_data.push(glass_distance_array);
            my_data.push(light_lux_array);
            my_data.push(motor_pause_array);
            my_data.push(system_pause_array);
            my_data.push(system_start_array);
            my_data.push(track_number_array);
            my_data.push(volume_array);
            */

            var newest_data = data[0];
            $("#volume_value").html(newest_data.volume);
            $("#motor_pause_value").html(newest_data.motor_pause);
            $("#glass_distance_value").html(newest_data.glass_distance);
            $("#light_lux_value").html(newest_data.light_lux);
            $("#system_start_value").html(newest_data.system_start);
            $("#system_pause_value").html(newest_data.system_pause);
            $("#track_number_value").html(newest_data.track_number);

            var my_data = [volume_array, track_number_array, system_start_array, system_pause_array, motor_pause_array, light_lux_array, glass_distance_array];
            
            handleData(my_data);
            return my_data;
        },
        complete: function () {
            return my_data;
            setTimeout(poll_lsd1_data, 5000);
        }
    })
    return my_data;
};

get_sensor_data();


$(document).ready(function()
{

    $( "#playback_control" ).click(function()
    {
        console.log("Output Pin/LED clicked")
        if($(this).prop('checked'))
            //checked
            $.ajax
            ({
                url: 'https://api.mongolab.com/api/1/databases/musiclab/collections/control_play?apiKey=DjDKE7adIsCNxYsls6ItXSR67DquF-11',
                type: 'PUT',
                contentType: "application/json",
                data: JSON.stringify({'_id':{"$oid":'56aeaaf9e4b0102fef23e1d1'},'command_value': 1}),
                success: function() { console.log("On Sent!");
                    alert('On Sent!'); }
            });
        else
            //unchecked
            $.ajax
            ({
                url: 'https://api.mongolab.com/api/1/databases/musiclab/collections/control_play?apiKey=DjDKE7adIsCNxYsls6ItXSR67DquF-11',
                type: 'PUT',
                contentType: "application/json",
                data: JSON.stringify({'_id':{"$oid":'56aeaaf9e4b0102fef23e1d1'},'command_value': 0}),
                success: function() { console.log("Off Sent!");
                    alert('Off Sent!'); }
            });
    });
        
    $( "#song_select_controller" ).click(function() {
        
        var selected_item = $(this).val()
        console.log(selected_item)
        if (selected_item === "JingleBells")
            $.ajax
            ({
                url: 'https://api.mongolab.com/api/1/databases/musiclab/collections/music?apiKey=DjDKE7adIsCNxYsls6ItXSR67DquF-11',
                type: 'PUT',
                contentType: "application/json",
                data: JSON.stringify({'_id':{"$oid":'56ad3e1de4b0b133d46d1f42'},'track_id': 1}),
                success: function() { console.log("JingleBells Sent!");
                    }
            });
        else if (selected_item === "Starcraft")
            $.ajax
            ({
                url: 'https://api.mongolab.com/api/1/databases/musiclab/collections/music?apiKey=DjDKE7adIsCNxYsls6ItXSR67DquF-11',
                type: 'PUT',
                contentType: "application/json",
                data: JSON.stringify({'_id':{"$oid":'56ad3e1de4b0b133d46d1f42'},'track_id': 2}),
                success: function() { console.log("Starcraft Sent!");
                    }				
            });				
        else if (selected_item === "MegaMan")
            $.ajax
            ({
                url: 'https://api.mongolab.com/api/1/databases/musiclab/collections/music?apiKey=DjDKE7adIsCNxYsls6ItXSR67DquF-11',
                type: 'PUT',
                contentType: "application/json",
                data: JSON.stringify({'_id':{"$oid":'56ad3e1de4b0b133d46d1f42'},'track_id': 3}),
                success: function() { console.log("MegaMan Sent!");
                    }
            });			
        else if (selected_item === "Airplane")
            $.ajax
            ({
                url: 'https://api.mongolab.com/api/1/databases/musiclab/collections/music?apiKey=DjDKE7adIsCNxYsls6ItXSR67DquF-11',
                type: 'PUT',
                contentType: "application/json",
                data: JSON.stringify({'_id':{"$oid":'56ad3e1de4b0b133d46d1f42'},'track_id': 4}),
                success: function() {
                    console.log("Airplane Sent!");
                    }
            });
    });
});