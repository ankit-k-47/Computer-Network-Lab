set ns [new Simulator]
set nd [open 2.tr w]
set nf [open 2.nam w]
$ns trace-all $nd
$ns namtrace-all $nf

proc finish { } {
    global ns nd nf
    $ns flush-trace
    close $nd
    close $nf 
    exec nam 2.nam &
    exit 0
}

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]

$ns duplex-link $n0 $n2 1Mb 10ms DropTail
$ns duplex-link $n1 $n2 1Mb 10ms DropTail
$ns duplex-link $n2 $n3 125Kb 10ms DropTail
$ns queue-limit $n2 $n3 2

set tcp0 [new Agent/TCP]
set tcp1 [new Agent/TCP]
set sink0 [new Agent/TCPSink]
set sink1 [new Agent/TCPSink]
$ns attach-agent $n0 $tcp0
$ns attach-agent $n1 $tcp1
$ns attach-agent $n3 $sink0
$ns attach-agent $n3 $sink1

$ns connect $tcp0 $sink0
$ns connect $tcp1 $sink1

set ftp0 [new Application/FTP]
set tel0 [new Application/Telnet]
$ftp0 attach-agent $tcp0
$tel0 attach-agent $tcp1

$ns at 0.5 "$ftp0 start"
$ns at 1.0 "$tel0 start"
$ns at 4.5 "$ftp0 stop"
$ns at 4.5 "$tel0 stop"
$ns at 5.0 "finish"
$ns run