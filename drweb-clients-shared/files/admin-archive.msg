From: "DrWeb-DAEMON" $FILTER_MAIL$
To: "AV-Administrator" $POSTMASTER$
Subject: A prohibited archive has been detected
Content-Type: multipart/mixed;
 boundary="001-DrWeb-MailFilter-Notification"
MIME-Version: 1.0

--001-DrWeb-MailFilter-Notification
Content-Type: text/plain; charset=us-ascii

Dear Postmaster,

the message with following attributes has not been delivered, because 
contains an object which violates archive restrictions.

Sender = $SENDER$
Recipients = $RCPTS$
Subject = $SUBJECT$
Message-ID = $MSGID$

--- Dr.Web report ---
Dr.Web detailed report:
$DAEMON_REPORT$
Dr.Web scanning statistic:
$SCAN_STAT$
--- Dr.Web report ---

--001-DrWeb-MailFilter-Notification
Content-Type: text/plain

$FULLHEADERS$
--001-DrWeb-MailFilter-Notification--
