# pkg_cmp_summary
pkg_cmp_summary src_summary.txt src_summary2.txt | sort -k2,2 |
cmp 'pkg_cmp_summary      #1' \
'- ap2-vhost-ldap 1.2.0nb1
- ap22-vhost-ldap 1.2.0nb1
= awk-pkgsrc-dewey 0.5.6 0.5.6
= checkperms 1.10 1.10
2 dict-client
< dict-server 1.10.11nb2 1.11.0
= dictem 0.82 0.82
+ digest 99.99.99
= distbb 0.22.0 0.22.0
= emacs 22.1nb6 22.1nb6
= gmake 3.81 3.81
= jpeg 6bnb4 6bnb4
= libltdl 1.5.24 1.5.24
= libmaa 1.0.1nb1 1.0.1nb1
= libtool-base 1.5.24nb6 1.5.24nb6
= libungif 4.1.4nb1 4.1.4nb1
- netcat 1.10nb2
= paexec 0.10.0nb1 0.10.0nb1
= perl 5.8.8nb8 5.8.8nb8
< pipestatus 0.4.0 0.5.0
= pkg-config 0.23 0.23
= pkg_online 0.5.0nb2 0.5.0nb2
= pkg_online-client 0.5.0 0.5.0
= pkg_online-server 0.5.0 0.5.0
= pkg_summary-utils 0.18.1 0.18.1
= png 1.2.32beta01 1.2.32beta01
> runawk 0.14.3 0.13.0
= tiff 3.8.2nb4 3.8.2nb4
- x11-links 0.38
'

pkg_cmp_summary -e src_summary.txt src_summary2.txt | sort -k2,2 |
cmp 'pkg_cmp_summary -e   #1.1' \
'- ap2-vhost-ldap 1.2.0nb1
- ap22-vhost-ldap 1.2.0nb1
= awk-pkgsrc-dewey 0.5.6 0.5.6
= checkperms 1.10 1.10
= dict-client 1.10.11nb2
= dict-client 1.9.15nb2
< dict-server 1.10.11nb2 1.11.0
= dictem 0.82 0.82
+ digest 99.99.99
= distbb 0.22.0 0.22.0
= emacs 22.1nb6 22.1nb6
= gmake 3.81 3.81
= jpeg 6bnb4 6bnb4
= libltdl 1.5.24 1.5.24
= libmaa 1.0.1nb1 1.0.1nb1
= libtool-base 1.5.24nb6 1.5.24nb6
= libungif 4.1.4nb1 4.1.4nb1
- netcat 1.10nb2
= paexec 0.10.0nb1 0.10.0nb1
= perl 5.8.8nb8 5.8.8nb8
< pipestatus 0.4.0 0.5.0
= pkg-config 0.23 0.23
= pkg_online 0.5.0nb2 0.5.0nb2
= pkg_online-client 0.5.0 0.5.0
= pkg_online-server 0.5.0 0.5.0
= pkg_summary-utils 0.18.1 0.18.1
= png 1.2.32beta01 1.2.32beta01
> runawk 0.14.3 0.13.0
= tiff 3.8.2nb4 3.8.2nb4
- x11-links 0.38
'

pkg_cmp_summary -p src_summary.txt src_summary2.txt | sort -k2,2 |
cmp 'pkg_cmp_summary -p   #2' \
'= devel/gmake gmake 3.81 3.81
= devel/libltdl libltdl 1.5.24 1.5.24
= devel/libmaa libmaa 1.0.1nb1 1.0.1nb1
= devel/libtool-base libtool-base 1.5.24nb6 1.5.24nb6
< devel/pipestatus pipestatus 0.4.0 0.5.0
= devel/pkg-config pkg-config 0.23 0.23
= editors/emacs emacs 22.1nb6 22.1nb6
= graphics/jpeg jpeg 6bnb4 6bnb4
= graphics/libungif libungif 4.1.4nb1 4.1.4nb1
= graphics/png png 1.2.32beta01 1.2.32beta01
= graphics/tiff tiff 3.8.2nb4 3.8.2nb4
= lang/perl5 perl 5.8.8nb8 5.8.8nb8
- net/netcat netcat 1.10nb2
+ pkgtools/digest digest 99.99.99
- pkgtools/x11-links x11-links 0.38
= sysutils/checkperms checkperms 1.10 1.10
= textproc/dict-client dict-client 1.9.15nb2 1.9.15nb2
= textproc/dictem dictem 0.82 0.82
= wip/awk-pkgsrc-dewey awk-pkgsrc-dewey 0.5.6 0.5.6
= wip/dict-client dict-client 1.10.11nb2 1.10.11nb2
< wip/dict-server dict-server 1.10.11nb2 1.11.0
= wip/distbb distbb 0.22.0 0.22.0
= wip/paexec paexec 0.10.0nb1 0.10.0nb1
= wip/pkg_online pkg_online 0.5.0nb2 0.5.0nb2
= wip/pkg_online-client pkg_online-client 0.5.0 0.5.0
= wip/pkg_online-server pkg_online-server 0.5.0 0.5.0
= wip/pkg_summary-utils pkg_summary-utils 0.18.1 0.18.1
> wip/runawk runawk 0.14.3 0.13.0
- www/ap2-vhost-ldap:PKG_APACHE=apache2 ap2-vhost-ldap 1.2.0nb1
- www/ap22-vhost-ldap:PKG_APACHE=apache22 ap22-vhost-ldap 1.2.0nb1
'

pkg_cmp_summary src_summary4.txt src_summary5.txt | sort -k2,2 |
cmp 'pkg_cmp_summary      #4' \
'= dictem 1.0.0 1.0.0
'

pkg_cmp_summary -p src_summary4.txt src_summary5.txt | sort -k2,2 |
cmp 'pkg_cmp_summary -p   #5' \
'- textproc/dictem dictem 1.0.0
+ wip/dictem dictem 1.0.0
'

pkg_cmp_summary -c src_summary4.txt src_summary5.txt | sort -k2,2 |
cmp 'pkg_cmp_summary -c   #7' \
'! dictem 1.0.0 1.0.0
'

pkg_cmp_summary -cp src_summary4.txt src_summary6.txt | sort -k2,2 |
cmp 'pkg_cmp_summary -cp  #8' \
'! textproc/dictem dictem 1.0.0 1.0.0
'

pkg_cmp_summary -P src_summary.txt src_summary2.txt | sort -k2,2 |
cmp 'pkg_cmp_summary -P   #9' \
'= devel/gmake
= devel/libltdl
= devel/libmaa
= devel/libtool-base
= devel/pipestatus
= devel/pkg-config
= editors/emacs
= graphics/jpeg
= graphics/libungif
= graphics/png
= graphics/tiff
= lang/perl5
- net/netcat
+ pkgtools/digest
- pkgtools/x11-links
= sysutils/checkperms
= textproc/dict-client
= textproc/dictem
= wip/awk-pkgsrc-dewey
= wip/dict-client
= wip/dict-server
= wip/distbb
= wip/paexec
= wip/pkg_online
= wip/pkg_online-client
= wip/pkg_online-server
= wip/pkg_summary-utils
= wip/runawk
- www/ap2-vhost-ldap:PKG_APACHE=apache2
- www/ap22-vhost-ldap:PKG_APACHE=apache22
'

if test -f "$objdir"/summary_micro.txt -o -f "$objdir"/summary_full.txt; then
    pkg_cmp_summary -p "$objdir"/summary_micro.txt "$objdir"/summary_full.txt |
    grep -v '^=' |
    cmp 'pkg_cmp_summary -p   #10' \
''
fi

pkg_cmp_summary -d summary1.txt summary2.txt |
cmp 'pkg_cmp_summary -d   #11' \
'! baz 1.2.3 1.2.3
'

pkg_cmp_summary -d summary2.txt summary1.txt |
cmp 'pkg_cmp_summary -d   #12' \
'! baz 1.2.3 1.2.3
'

pkg_cmp_summary -d summary1.txt summary4.txt |
cmp 'pkg_cmp_summary -d   #13' \
'! baz 1.2.3 1.2.3
'

pkg_cmp_summary -d summary4.txt summary1.txt |
cmp 'pkg_cmp_summary -d   #14' \
'! baz 1.2.3 1.2.3
'

pkg_cmp_summary -d summary1.txt summary3.txt |
cmp 'pkg_cmp_summary -d   #15' \
'= baz 1.2.3 1.2.3
'

pkg_cmp_summary -d summary3.txt summary1.txt |
cmp 'pkg_cmp_summary -d   #16' \
'= baz 1.2.3 1.2.3
'

pkg_cmp_summary -pe2 src_summary14.txt bin_summary3.txt | sort |
cmp 'pkg_cmp_summary -pe2 #17.1' \
'! lang/ruby ruby 1.9.2
= archivers/php-zip archivers/php-zip php5-zip 5.2.15.1.8.11
= archivers/php-zip:PHP_VERSION_REQD=52 archivers/php-zip php5-zip 5.2.15
= archivers/php-zip:PHP_VERSION_REQD=53 archivers/php-zip php53-zip 5.3.4 5.3.4
= lang/ruby lang/ruby ruby 1.8.7.302
'

pkg_cmp_summary -pe src_summary14.txt bin_summary3.txt | sort |
cmp 'pkg_cmp_summary -pe  #17.2' \
'! lang/ruby ruby 1.9.2
= archivers/php-zip php5-zip 5.2.15
= archivers/php-zip php5-zip 5.2.15.1.8.11
= archivers/php-zip php53-zip 5.3.4 5.3.4
= lang/ruby ruby 1.8.7.302
'

pkg_cmp_summary -p src_summary14.txt bin_summary3.txt | sort |
cmp 'pkg_cmp_summary -p   #17.3' \
'2 archivers/php-zip php5-zip
2 lang/ruby ruby
= archivers/php-zip php53-zip 5.3.4 5.3.4
'

pkg_cmp_summary -pe2 src_summary14.txt - < src_summary14.txt | sort |
cmp 'pkg_cmp_summary -pe2 #17.4' \
'= archivers/php-zip archivers/php-zip php5-zip 5.2.15.1.8.11
= archivers/php-zip:PHP_VERSION_REQD=52 archivers/php-zip:PHP_VERSION_REQD=52 php5-zip 5.2.15
= archivers/php-zip:PHP_VERSION_REQD=53 archivers/php-zip:PHP_VERSION_REQD=53 php53-zip 5.3.4 5.3.4
= lang/ruby lang/ruby ruby 1.8.7.302
= lang/ruby:RUBY_VERSION_REQD=19 lang/ruby:RUBY_VERSION_REQD=19 ruby 1.9.2pl0
'

pkg_cmp_summary -pe2 bin_summary3.txt - < bin_summary3.txt | sort |
cmp 'pkg_cmp_summary      #17.5' \
'= archivers/php-zip archivers/php-zip php5-zip 5.2.15
= archivers/php-zip archivers/php-zip php5-zip 5.2.15.1.8.11
= archivers/php-zip archivers/php-zip php53-zip 5.3.4 5.3.4
= lang/ruby lang/ruby ruby 1.8.7.302
= lang/ruby lang/ruby ruby 1.9.2
'

pkg_cmp_summary -pu bin_summary2.txt - < bin_summary3.txt | sort |
cmp 'pkg_cmp_summary -pu  #18.1' \
'+ archivers/php-zip php5-zip 5.2.15
+ archivers/php-zip php5-zip 5.2.15.1.8.11
+ archivers/php-zip php53-zip 5.3.4
+ lang/ruby ruby 1.8.7.302
+ lang/ruby ruby 1.9.2
- devel/libmaa libmaa 1.2.0 U
- devel/pipestatus pipestatus 0.6.0 U
- pkgtools/digest digest 20080510 A
- textproc/dict-client dict-client 1.11.2 U
- textproc/dict-server dict-server 1.11.2 U
- wip/distbb distbb 0.38.1 A
- wip/mk-configure mk-configure 0.21.0 A
- wip/paexec paexec 0.15.0 A
- wip/pkg_status pkg_status 0.11 A
- wip/pkg_summary-utils pkg_summary-utils 0.49.1nb1 A
- wip/pkgnih pkgnih 0.3.1 U
- wip/runawk runawk 1.2.0 A
'

pkg_cmp_summary -pb bin_summary1.txt bin_summary2.txt | sort |
cmp 'pkg_cmp_summary -pb  #18.2' \
'! wip/pkgnih pkgnih 0.3.1 0.3.1
+ pkgtools/digest digest 20080510
+ textproc/dict-client dict-client 1.11.2
+ textproc/dict-server dict-server 1.11.2
+ wip/mk-configure mk-configure 0.21.0
+ wip/pkg_status pkg_status 0.11
- devel/gmake gmake 3.81
- devel/libtool-base libtool-base 1.5.26nb2
- net/netcat netcat 1.10nb2
- sysutils/checkperms checkperms 1.10
- wip/awk-pkgsrc-dewey awk-pkgsrc-dewey 0.5.6
- wip/dict-client dict-client 1.11.2
- wip/dict-server dict-server 1.11.2
- wip/pkg_conflicts pkg_conflicts 0.4.0
- wip/pkg_online pkg_online 0.9.1
- wip/pkg_online-client pkg_online-client 0.9.1
- wip/pkg_online-server pkg_online-server 0.9.1
< devel/libmaa libmaa 1.1.0 1.2.0
< wip/distbb distbb 0.33.0 0.38.1
< wip/paexec paexec 0.13.0nb1 0.15.0
< wip/pkg_summary-utils pkg_summary-utils 0.35rc1 0.49.1nb1
< wip/runawk runawk 0.18.0 1.2.0
= devel/pipestatus pipestatus 0.6.0 0.6.0
'

pkg_cmp_summary -a automatic,try_out bin_summary91.txt bin_summary92.txt |
cmp 'pkg_cmp_summary -a   #19.1' \
'= f 3.4.5 3.4.5
+ e 0.1.1
> h 0.0.2 0.0.1
! b 2.2.2 2.2.2
! a 1.1.1 1.1.1
! c 3.4.5 3.4.5
= g 3.4.9 3.4.9
< i 0.1 0.4
- d 0.1.1
'

pkg_cmp_summary -a automatic,try_out bin_summary91.txt bin_summary92.txt |
cmp 'pkg_cmp_summary -Ea  #19.2' \
'= f 3.4.5 3.4.5
+ e 0.1.1
> h 0.0.2 0.0.1
! b 2.2.2 2.2.2
! a 1.1.1 1.1.1
! c 3.4.5 3.4.5
= g 3.4.9 3.4.9
< i 0.1 0.4
- d 0.1.1
'

pkg_cmp_summary -A automatic,try_out bin_summary91.txt bin_summary92.txt |
cmp 'pkg_cmp_summary -A   #20.1' \
'= f 3.4.5 3.4.5

+ e 0.1.1
 automatic 
 automatic yes
 try_out 
 try_out yes

> h 0.0.2 0.0.1
 automatic 
 automatic yes
 try_out 
 try_out yes

! b 2.2.2 2.2.2
 try_out yes
 try_out 

! a 1.1.1 1.1.1
 automatic 
 automatic yes
 try_out yes
 try_out 

! c 3.4.5 3.4.5
 automatic 
 automatic yes

= g 3.4.9 3.4.9

< i 0.1 0.4
 automatic 
 automatic yes
 try_out 
 try_out yes

- d 0.1.1
 automatic yes
 automatic 

'

pkg_cmp_summary -a automatic -A try_out bin_summary91.txt bin_summary92.txt |
cmp 'pkg_cmp_summary -Aa  #20.2' \
'= f 3.4.5 3.4.5

+ e 0.1.1
 try_out 
 try_out yes

> h 0.0.2 0.0.1
 try_out 
 try_out yes

! b 2.2.2 2.2.2
 try_out yes
 try_out 

! a 1.1.1 1.1.1
 try_out yes
 try_out 

! c 3.4.5 3.4.5

= g 3.4.9 3.4.9

< i 0.1 0.4
 try_out 
 try_out yes

- d 0.1.1

'

pkg_cmp_summary -A automatic -atry_out bin_summary91.txt bin_summary92.txt |
cmp 'pkg_cmp_summary -Aa  #20.3' \
'= f 3.4.5 3.4.5

+ e 0.1.1
 automatic 
 automatic yes

> h 0.0.2 0.0.1
 automatic 
 automatic yes

! b 2.2.2 2.2.2

! a 1.1.1 1.1.1
 automatic 
 automatic yes

! c 3.4.5 3.4.5
 automatic 
 automatic yes

= g 3.4.9 3.4.9

< i 0.1 0.4
 automatic 
 automatic yes

- d 0.1.1
 automatic yes
 automatic 

'

pkg_cmp_summary -A automatic,try_out -E bin_summary91.txt bin_summary92.txt |
cmp 'pkg_cmp_summary -AE  #20.4' \
'= f 3.4.5 3.4.5
 automatic yes
 automatic yes
 try_out yes
 try_out yes

+ e 0.1.1
 automatic 
 automatic yes
 try_out 
 try_out yes

> h 0.0.2 0.0.1
 automatic 
 automatic yes
 try_out 
 try_out yes

! b 2.2.2 2.2.2
 automatic 
 automatic 
 try_out yes
 try_out 

! a 1.1.1 1.1.1
 automatic 
 automatic yes
 try_out yes
 try_out 

! c 3.4.5 3.4.5
 automatic 
 automatic yes
 try_out 
 try_out 

= g 3.4.9 3.4.9
 automatic 
 automatic 
 try_out 
 try_out 

< i 0.1 0.4
 automatic 
 automatic yes
 try_out 
 try_out yes

- d 0.1.1
 automatic yes
 automatic 
 try_out 
 try_out 

'

pkg_cmp_summary -Ea automatic -A try_out bin_summary91.txt bin_summary92.txt |
cmp 'pkg_cmp_summary -Aa  #20.5' \
'= f 3.4.5 3.4.5
 try_out yes
 try_out yes

+ e 0.1.1
 try_out 
 try_out yes

> h 0.0.2 0.0.1
 try_out 
 try_out yes

! b 2.2.2 2.2.2
 try_out yes
 try_out 

! a 1.1.1 1.1.1
 try_out yes
 try_out 

! c 3.4.5 3.4.5
 try_out 
 try_out 

= g 3.4.9 3.4.9
 try_out 
 try_out 

< i 0.1 0.4
 try_out 
 try_out yes

- d 0.1.1
 try_out 
 try_out 

'

pkg_cmp_summary -EA automatic -atry_out bin_summary91.txt bin_summary92.txt |
cmp 'pkg_cmp_summary -Aa  #20.6' \
'= f 3.4.5 3.4.5
 automatic yes
 automatic yes

+ e 0.1.1
 automatic 
 automatic yes

> h 0.0.2 0.0.1
 automatic 
 automatic yes

! b 2.2.2 2.2.2
 automatic 
 automatic 

! a 1.1.1 1.1.1
 automatic 
 automatic yes

! c 3.4.5 3.4.5
 automatic 
 automatic yes

= g 3.4.9 3.4.9
 automatic 
 automatic 

< i 0.1 0.4
 automatic 
 automatic yes

- d 0.1.1
 automatic yes
 automatic 

'
