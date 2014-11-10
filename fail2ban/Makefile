# $NetBSD: Makefile,v 1.7 2014/11/10 10:03:26 ahp-nils Exp $
#

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

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
USE_LANGUAGES=	# none
EGDIR=			${PREFIX}/share/examples/fail2ban
PKG_SYSCONFSUBDIR?=	fail2ban
DOCDIR=			${PREFIX}/share/doc/fail2ban
OWN_DIRS=		${PKG_SYSCONFDIR} ${PKG_SYSCONFDIR}/action.d/ ${PKG_SYSCONFDIR}/filter.d/ \
			${VARBASE}/run/fail2ban ${VARBASE}/db/fail2ban
INSTALLATION_DIRS+=	${PKGMANDIR}/man1/ ${EGDIR} ${EGDIR}/action.d/ ${EGDIR}/filter.d/ \
			${PKG_SYSCONFDIR} ${PKG_SYSCONFDIR}/action.d/ ${PKG_SYSCONFDIR}/filter.d/

.for config in fail2ban.conf jail.conf paths-common.conf paths-debian.conf paths-fedora.conf paths-freebsd.conf paths-osx.conf paths-netbsd.conf
CONF_FILES+=		${EGDIR}/${config} ${PKG_SYSCONFDIR}/${config}
.endfor


.for action in apf.conf badips.conf badips.py blocklist_de.conf bsd-ipfw.conf cloudflare.conf complain.conf dshield.conf dummy.conf firewallcmd-ipset.conf firewallcmd-new.conf hostsdeny.conf ipfilter.conf ipfw.conf iptables-allports.conf iptables-common.conf iptables-ipset-proto4.conf iptables-ipset-proto6-allports.conf iptables-ipset-proto6.conf iptables-multiport-log.conf iptables-multiport.conf iptables-new.conf iptables-xt_recent-echo.conf iptables.conf mail-buffered.conf mail-whois-lines.conf mail-whois.conf mail.conf mynetwatchman.conf osx-afctl.conf osx-ipfw.conf pf.conf route.conf sendmail-buffered.conf sendmail-common.conf sendmail-whois-lines.conf sendmail-whois-ipjailmatches.conf sendmail-whois-ipmatches.conf sendmail-whois-matches.conf sendmail-whois.conf sendmail.conf shorewall.conf smtp.py symbiosis-blacklist-allports.conf ufw.conf xarf-login-attack.conf
CONF_FILES+=		${EGDIR}/action.d/${action} ${PKG_SYSCONFDIR}/action.d/${action}
.endfor

.for filter in 3proxy.conf apache-auth.conf apache-badbots.conf apache-botsearch.conf apache-common.conf apache-modsecurity.conf apache-nohome.conf apache-noscript.conf apache-overflows.conf apache-shellshock.conf assp.conf asterisk.conf common.conf counter-strike.conf courier-auth.conf courier-smtp.conf cyrus-imap.conf dovecot.conf directadmin.conf dropbear.conf ejabberd-auth.conf exim-common.conf exim-spam.conf exim.conf freeswitch.conf groupoffice.conf gssftpd.conf guacamole.conf horde.conf kerio.conf lighttpd-auth.conf monit.conf mysqld-auth.conf nagios.conf named-refused.conf nginx-http-auth.conf nsd.conf openwebmail.conf oracleims.conf pam-generic.conf perdition.conf php-url-fopen.conf portsentry.conf postfix-sasl.conf postfix.conf proftpd.conf pure-ftpd.conf qmail.conf recidive.conf roundcube-auth.conf selinux-common.conf selinux-ssh.conf sendmail-auth.conf sendmail-reject.conf sieve.conf sogo-auth.conf solid-pop3d.conf squid.conf squirrelmail.conf sshd-ddos.conf sshd.conf stunnel.conf suhosin.conf tine20.conf uwimap-auth.conf vsftpd.conf webmin-auth.conf wuftpd.conf xinetd-fail.conf
CONF_FILES+=		${EGDIR}/filter.d/${filter} ${PKG_SYSCONFDIR}/filter.d/${filter}
.endfor

AUTO_MKDIRS=		yes
MANPAGES=		fail2ban-client.1 fail2ban-regex.1 fail2ban-server.1

FILES_SUBST+=		PYTHON_INTERP=${PYTHONBIN:Q}
BUILD_DEFS+=		PYTHON_INTERP
BUILD_DEFS+=		VARBASE
WRKSRC=			${WRKDIR}/fail2ban-${GHCOMMIT}
RCD_SCRIPTS=		fail2ban

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Substituting paths variables.
SUBST_FILES.paths=	${WRKSRC}/bin/fail2ban-client
SUBST_FILES.paths+=	${WRKSRC}/fail2ban/client/configreader.py
SUBST_FILES.paths+=	${WRKSRC}/man/fail2ban-client.1
SUBST_FILES.paths+=	${WRKSRC}/man/fail2ban-client.h2m
SUBST_FILES.paths+=	${WRKSRC}/setup.py
SUBST_FILES.paths+=	${WRKSRC}/config/fail2ban.conf
#SUBST_FILES.paths+=	${WRKSRC}/config/jail.conf
SUBST_SED.paths=	-e 's,/etc,${PREFIX}/etc,g'
SUBST_SED.paths+=	-e 's,/var/lib,${VARBASE}/db,g'
SUBST_SED.paths+=	-e 's,/var,${VARBASE},g'
SUBST_SED.paths+=	-e 's,/usr/share,${PREFIX}/share,g'
SUBST_SED.paths+=	-e 's,/usr/share,${PREFIX}/share,g'
#SUBST_SED.paths+=	-e 's,paths-debian.conf,paths-netbsd.conf,g'

SUBST_CLASSES+=		install
SUBST_STAGE.install=	pre-install
SUBST_MESSAGE.install=	correcting installation path
SUBST_FILES.install=	${WRKSRC}/setup.py
SUBST_SED.install=	-e 's,${PREFIX}/etc,${EGDIR},g'

post-extract:
	${CP} ${FILESDIR}/paths-netbsd.conf ${WRKSRC}/config/paths-netbsd.conf

post-install:
.for f in ${MANPAGES}
	${INSTALL_MAN} ${WRKSRC}/man/${f} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
.endfor
	${INSTALL_DATA} ${WRKSRC}/config/*.conf ${DESTDIR}${EGDIR}/
	${INSTALL_DATA} ${WRKSRC}/config/action.d/* ${DESTDIR}${EGDIR}/action.d/
	${INSTALL_DATA} ${WRKSRC}/config/filter.d/* ${DESTDIR}${EGDIR}/filter.d/
.for docfile in README.md README.Solaris DEVELOP FILTERS doc/run-rootless.txt
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${DESTDIR}${DOCDIR}/
.endfor

.include "options.mk"

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
