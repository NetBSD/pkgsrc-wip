# $NetBSD: Makefile,v 1.1 2005/04/10 21:53:57 rillig Exp $

DISTNAME=		openbsd-ntpd-0.0
CATEGORIES=		net time
CVS_REPOSITORY=		anoncvs@anoncvs.openbsd.org:/cvs
CVS_MODULE=		src/usr.sbin/ntpd

MAKE_ENV+=		BINDIR=${PREFIX:Q}/sbin
MAKE_ENV+=		MANDIR=${PREFIX:Q}/man

CONFLICTS+=		ntp4-[0-9]* openntpd-[0-9]*

OPSYSVARS+=		NTPD_USER
NTPD_USER.OpenBSD?=	_ntp
NTPD_USER.*?=		ntpd
CPPFLAGS+=		-DNTPD_USER=\"${NTPD_USER:Q}\"

.include "../../wip/mk/cvs-package.mk"
.include "../../mk/bsd.pkg.mk"
