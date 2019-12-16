Action()
{

	web_url("WebTours", 
		"URL=http://127.0.0.1:1080/WebTours", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t37.inf", 
		"Mode=HTML", 
		LAST);

	web_url("header.html", 
		"URL=http://127.0.0.1:1080/WebTours/header.html", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://127.0.0.1:1080/WebTours/", 
		"Snapshot=t38.inf", 
		"Mode=HTML", 
		LAST);

	web_url("welcome.pl", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?signOff=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/WebTours/", 
		"Snapshot=t39.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "2&3");

	lr_think_time(14);

	web_url("repair", 
		"URL=https://self-repair.mozilla.org/en-US/repair", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t40.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(49);

	lr_start_transaction("Flight_test");

	lr_start_transaction("Login");

	web_custom_request("ocsp.digicert.com", 
		"URL=http://ocsp.digicert.com/", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/ocsp-response", 
		"Referer=", 
		"Snapshot=t41.inf", 
		"Mode=HTML", 
		"EncType=application/ocsp-request", 
		"BodyBinary=0Q0O0M0K0I0\t\\x06\\x05+\\x0E\\x03\\x02\\x1A\\x05\\x00\\x04\\x14\\x18\\xF8\\x85\\xA9\\x97\\x1C\\xDC{\\xEF\\x86\tm\\x01\\x98<\\xA8\\xF9\\x9F%V\\x04\\x14$\\xF2.N\\x0F\\xBD\\xCA\\xF7>)U\\xCAr\\x8Di\\x87VD\\xE9z\\x02\\x10\r\\x91\\x88z\\xD7\\xF0\\xB5\\xA5z\\xAEgE\\x8D$\\xFE\\x81", 
		LAST);

	web_submit_data("login.pl", 
		"Action=http://127.0.0.1:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t42.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=127696.26690968zfziDHzpHcQVzzzHDQtVApczADHf", ENDITEM, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=login.x", "Value=75", ENDITEM, 
		"Name=login.y", "Value=15", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		LAST);

	web_url("update.xml", 
		"URL=https://aus4.mozilla.org/update/3/GMP/40.0.3/20150826023504/WINNT_x86-msvc/en-US/release/Windows_NT%2010.0.0.0%20(x64)/default/default/update.xml", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=", 
		"Snapshot=t43.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Login",LR_AUTO);

	lr_start_transaction("Select_flights");

	web_url("welcome.pl_2", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t44.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Select_flights",LR_AUTO);

	lr_think_time(24);

	lr_start_transaction("Filling_fields");

	web_submit_data("reservations.pl", 
		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t45.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value=Denver", ENDITEM, 
		"Name=departDate", "Value=12/16/2019", ENDITEM, 
		"Name=arrive", "Value=Los Angeles", ENDITEM, 
		"Name=returnDate", "Value=12/17/2019", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value=Aisle", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=findFlights.x", "Value=35", ENDITEM, 
		"Name=findFlights.y", "Value=10", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		LAST);

	web_submit_data("reservations.pl_2", 
		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Snapshot=t46.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=032;238;12/16/2019", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=seatPref", "Value=Aisle", ENDITEM, 
		"Name=reserveFlights.x", "Value=54", ENDITEM, 
		"Name=reserveFlights.y", "Value=7", ENDITEM, 
		LAST);

	lr_end_transaction("Filling_fields",LR_AUTO);

	lr_think_time(40);

	lr_start_transaction("Filling_payment_fields");

	web_submit_data("reservations.pl_3", 
		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Snapshot=t47.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value=Jojo", ENDITEM, 
		"Name=lastName", "Value=Bean", ENDITEM, 
		"Name=address1", "Value=", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=pass1", "Value=Jojo Bean", ENDITEM, 
		"Name=creditCard", "Value=12345678", ENDITEM, 
		"Name=expDate", "Value=14/16", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=seatPref", "Value=Aisle", ENDITEM, 
		"Name=outboundFlight", "Value=032;238;12/16/2019", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value=", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=buyFlights.x", "Value=59", ENDITEM, 
		"Name=buyFlights.y", "Value=7", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		LAST);

	lr_end_transaction("Filling_payment_fields",LR_AUTO);

	lr_think_time(20);

	lr_start_transaction("Select_itinerary");

	web_url("Itinerary Button", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t48.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Select_itinerary",LR_AUTO);

	lr_think_time(18);

	lr_start_transaction("select_sign_off");

	web_url("SignOff Button", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t49.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("select_sign_off",LR_AUTO);

	lr_end_transaction("Flight_test",LR_AUTO);

	return 0;
}