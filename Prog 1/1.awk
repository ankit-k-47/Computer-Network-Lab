BEGIN{
    dcount = 0;
    rcount = 0;
}

{
    event = $1
    if(event == "r"){
        rcount++;
    }
    if(event == "d"){
        dcount++;
    }
}

END{
    printf("Number of packets recieved is %d", rcount);
    printf("Number of packets dropped is %d", dcount);
}