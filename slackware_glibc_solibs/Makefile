# $NetBSD: Makefile,v 1.4 2004/03/16 21:32:52 mpasternak Exp $
# $Id: Makefile,v 1.4 2004/03/16 21:32:52 mpasternak Exp $
#

DISTNAME=		glibc-solibs-2.3.2-i486-5
PKGNAME=		slackware_glibc_solibs-2.3.2
CATEGORIES=		emulators
MASTER_SITES=		${SLACKWARE_MASTER_SITES}

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
	${EMULDIR}/sbin/ldconfig

.include "../../wip/slackware_compat/Makefile.common"
.include "../../mk/bsd.pkg.mk"
