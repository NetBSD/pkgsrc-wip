# $NetBSD: Makefile,v 1.5 2014/10/28 19:49:09 ahp-nils Exp $
#

#DISTNAME=	fail2ban-0.8.4
#PKGREVISION=	2
CATEGORIES=	security
GHCOMMIT=	a0115ee4582e0befbcd7664989b6ab87f8d226a2
DISTNAME=	${GHCOMMIT}
PKGNAME=	fail2ban-0.9.1
MASTER_SITES=	https://github.com/fail2ban/fail2ban/archive/
EXTRACT_SUFX=	.zip

MAINTAINER=	ahp-nils@users.sourceforge.net
HOMEPAGE=	http://www.fail2ban.org/
COMMENT=	Scans log files and bans IP that makes too many password failures
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none
EGDIR=			${PREFIX}/share/examples/fail2ban
OWN_DIRS=		${PKG_SYSCONFDIR}/fail2ban ${PKG_SYSCONFDIR}/fail2ban/action.d/ ${PKG_SYSCONFDIR}/fail2ban/filter.d/
INSTALLATION_DIRS+=	${PKGMANDIR}/man1/ ${EGDIR} ${EGDIR}/action.d/ ${EGDIR}/filter.d/ \
			${PKG_SYSCONFDIR} ${PKG_SYSCONFDIR}/action.d/ ${PKG_SYSCONFDIR}/filter.d/
.for base-conf in fail2ban.conf jail.conf paths-common.conf paths-debian.conf paths-fedora.conf paths-freebsd.conf paths-osx.conf
CONF_FILES+=		${EGDIR}/${base-conf} \
				${PKG_SYSCONFDIR}/fail2ban/${base-conf}
.endfor
.for action in apf.conf badips.conf badips.py blocklist_de.conf bsd-ipfw.conf cloudflare.conf complain.conf dshield.conf dummy.conf firewallcmd-ipset.conf firewallcmd-new.conf hostsdeny.conf ipfilter.conf ipfw.conf iptables-allports.conf iptables-common.conf iptables-ipset-proto4.conf iptables-ipset-proto6-allports.conf iptables-ipset-proto6.conf iptables-multiport-log.conf iptables-multiport.conf iptables-new.conf iptables-xt_recent-echo.conf iptables.conf mail-buffered.conf mail-whois-lines.conf mail-whois.conf mail.conf mynetwatchman.conf osx-afctl.conf osx-ipfw.conf pf.conf route.conf sendmail-buffered.conf sendmail-common.conf sendmail-whois-lines.conf sendmail-whois-ipjailmatches.conf sendmail-whois-ipmatches.conf sendmail-whois-matches.conf sendmail-whois.conf sendmail.conf shorewall.conf smtp.py symbiosis-blacklist-allports.conf ufw.conf xarf-login-attack.conf
CONF_FILES+=		${EGDIR}/action.d/${action} \
				${PKG_SYSCONFDIR}/fail2ban/action.d/${action}
.endfor

.for filter in 3proxy.conf apache-auth.conf apache-badbots.conf apache-botsearch.conf apache-common.conf apache-modsecurity.conf apache-nohome.conf apache-noscript.conf apache-overflows.conf apache-shellshock.conf assp.conf asterisk.conf common.conf counter-strike.conf courier-auth.conf courier-smtp.conf cyrus-imap.conf dovecot.conf directadmin.conf dropbear.conf ejabberd-auth.conf exim-common.conf exim-spam.conf exim.conf freeswitch.conf groupoffice.conf gssftpd.conf guacamole.conf horde.conf kerio.conf lighttpd-auth.conf monit.conf mysqld-auth.conf nagios.conf named-refused.conf nginx-http-auth.conf nsd.conf openwebmail.conf oracleims.conf pam-generic.conf perdition.conf php-url-fopen.conf portsentry.conf postfix-sasl.conf postfix.conf proftpd.conf pure-ftpd.conf qmail.conf recidive.conf roundcube-auth.conf selinux-common.conf selinux-ssh.conf sendmail-auth.conf sendmail-reject.conf sieve.conf sogo-auth.conf solid-pop3d.conf squid.conf squirrelmail.conf sshd-ddos.conf sshd.conf stunnel.conf suhosin.conf tine20.conf uwimap-auth.conf vsftpd.conf webmin-auth.conf wuftpd.conf xinetd-fail.conf
CONF_FILES+=		${EGDIR}/filter.d/${filter} \
				${PKG_SYSCONFDIR}/fail2ban/filter.d/${filter}
.endfor

AUTO_MKDIRS=		yes
MANPAGES=		fail2ban-client.1 fail2ban-regex.1 fail2ban-server.1

FILES_SUBST+=		PYTHON_INTERP=${PYTHONBIN:Q}
BUILD_DEFS+=		PYTHON_INTERP
WRKSRC=			${WRKDIR}/fail2ban-${GHCOMMIT}
RCD_SCRIPTS=	fail2ban

post-install:
.for f in ${MANPAGES}
	${INSTALL_MAN} ${WRKSRC}/man/${f} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
.endfor
	${INSTALL_DATA} ${WRKSRC}/config/*.conf ${DESTDIR}${EGDIR}/
	${INSTALL_DATA} ${WRKSRC}/config/action.d/* ${DESTDIR}${EGDIR}/action.d/
	#${INSTALL_DATA} ${WRKSRC}/config/action.d/* ${DESTDIR}${PKG_SYSCONFDIR}/action.d/
	${INSTALL_DATA} ${WRKSRC}/config/filter.d/* ${DESTDIR}${EGDIR}/filter.d/
	#${INSTALL_DATA} ${WRKSRC}/config/filter.d/* ${DESTDIR}${PKG_SYSCONFDIR}/filter.d/

.include "options.mk"

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
