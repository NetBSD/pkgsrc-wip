# $NetBSD: Makefile,v 1.2 2004/03/12 14:33:46 mpasternak Exp $
# $Id: Makefile,v 1.2 2004/03/12 14:33:46 mpasternak Exp $
#

DISTNAME=		slackware_glibc_solibs-2.3.2
CATEGORIES=		emulators
MASTER_SITES=		${SLACKWARE_MASTER_SITES}
DISTFILES=		glibc-solibs-2.3.2-i486-5.tgz

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://slackware.com
COMMENT=		Glibc and other important shared libraries for slackware emulation

LINUX_BASE_NODEPS=	# defined
SLACK_NO_INSTALL=	# we handle install procedure

DEPENDS=		slackware_aaa_base>=9.1.0:../../wip/slackware_aaa_base

.include "../../mk/bsd.prefs.mk"

post-install:
	cd ${EMULDIR} && ${SH} install/doinst.sh
	for a in /usr/lib /lib /usr/pkg/lib /usr/X11R6/lib /usr/local/lib; do \
		echo $$a >> ${EMULDIR}/etc/ld.so.conf; done
.if ${OPSYS} == "FreeBSD"
	/usr/bin/brandelf -t Linux ${EMULDIR}/sbin/ldconfig
.endif
	# || $${YES} is needed, it fails while *exiting* on my FreeBSD box,
	# no time to debug this now, maybe later
	${EMULDIR}/sbin/ldconfig || ${YES}

.include "../../wip/slackware_compat/Makefile.common"
.include "../../mk/bsd.pkg.mk"
