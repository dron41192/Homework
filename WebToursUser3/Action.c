Action()
{
	lr_start_transaction("Ticket_from_Denver_to_Zurich");

	lr_start_transaction("Login");

	web_reg_save_param_ex(
		"ParamName=SessionId",
		"LB=A HREF=\"",
		"RB=.pl",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/nav.pl*",
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
		"Name=userSession", "Value={SessionId}", ENDITEM, 
		"Name=username", "Value={name}", ENDITEM, 
		"Name=password", "Value={password}", ENDITEM, 
		"Name=login.x", "Value=75", ENDITEM, 
		"Name=login.y", "Value=15", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		LAST);

	lr_end_transaction("Login",LR_AUTO);

	lr_start_transaction("Select_flights");

	web_url("welcome.pl_2",
		"URL=http://127.0.0.1:1080/cgi-bin/{SessionId}.pl?page=search",
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
		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl?page={SessionId}",
		"Snapshot=t45.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=depart", "Value={departure}", ENDITEM,
		"Name=departDate", "Value={departdate}", ENDITEM,
		"Name=arrive", "Value={arrival}", ENDITEM,
		"Name=returnDate", "Value={returndate}", ENDITEM,
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
		"Name=seatType", "Value={typrofseat}", ENDITEM, 
		"Name=seatPref", "Value={seatingpref}", ENDITEM, 
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
		"URL=http://127.0.0.1:1080/cgi-bin/{SessionId}.pl?page=itinerary",
		"TargetFrame=body",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=flights",
		"Snapshot=t48.inf",
		"Mode=HTML",
		LAST);

	lr_end_transaction("Select_itinerary",LR_AUTO);

	lr_think_time(18);

	lr_start_transaction("Select_sign_off");

	web_url("SignOff Button",
		"URL=http://127.0.0.1:1080/cgi-bin/{SessionId}.pl?signOff=1",
		"TargetFrame=body",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=itinerary",
		"Snapshot=t49.inf",
		"Mode=HTML",
		LAST);

	lr_end_transaction("Select_sign_off",LR_AUTO);

	lr_end_transaction("Ticket_from_Denver_to_Zurich",LR_AUTO);

	return 0;
}