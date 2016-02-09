function get_actuator_data() {
    $.ajax({
        //url: "https://api.mongolab.com/api/1/databases/time_sync_project/collections/light_sensor_data1?q={'_id': {$gt: ".concat(lsd1_last_id, "}}&apiKey=Ya1oggJiF9qEsZfUExiS2OGHUW52tEvP"),
        url: "https://api.mongolab.com/api/1/databases/musiclab/collections/control_play?apiKey=DjDKE7adIsCNxYsls6ItXSR67DquF-11",
        dataType: "json",
        success: function (data) {
            console.log("Data from 'control_play' collection");
            console.log(data);
        }
    })
    $.ajax({
        url: "https://api.mongolab.com/api/1/databases/musiclab/collections/music?apiKey=DjDKE7adIsCNxYsls6ItXSR67DquF-11",
        dataType: "json",
        success: function (data) {
            console.log("Data from 'music' collection");
            console.log(data);
        }
    })
};

get_actuator_data();


function get_sensor_data() {
    $.ajax({
        url: "https://api.mongolab.com/api/1/databases/musiclab/collections/sensor_data?apiKey=DjDKE7adIsCNxYsls6ItXSR67DquF-11",
        dataType: "json",
        success: function (data) {
            console.log("Data from 'sensor_data' collection");
            console.log("Expected 322 Sensor Values");
            console.log(data);
        }
    })
};

get_sensor_data();


$(document).ready(function ()
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