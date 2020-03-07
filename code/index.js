var mysql = require('mysql');
var AWS = require("aws-sdk");

var pool = mysql.createPool({
	host     : 'shiiot.******.rds.cn-northwest-1.amazonaws.com.cn',
	user     : 'admin',
	password : '******',
	database : 'shiiotdb'
});

exports.handler =  (event, context, callback) => {
	// Receive Data from IoT Rule
	var eventText = JSON.stringify(event, null, 2);
    console.log("Received event:", eventText);
    var devid = (JSON.parse(eventText)).state.reported.devid;
    var timestamp = (JSON.parse(eventText)).state.reported.timestamp;
    var temperature = (JSON.parse(eventText)).state.reported.temperature;
	
	//prevent timeout from waiting event loop
	context.callbackWaitsForEmptyEventLoop = false;
	pool.getConnection(function(err, connection) {
	// Use the connection
	var insertSQL = 'insert into shiiottable (devid, msgtimestamp, temperature)values (?, ?, ?)';
	var params = [devid, timestamp, temperature];
	connection.query(insertSQL, params, function (error, results, fields) {
		// And done with the connection.
		connection.release();
		// Handle error after the release.
		if (error) 
			callback(error);
		else
			callback(null,results);
		console.log('The solution is: ', results);
		});
	});
};
