# $NetBSD: Makefile,v 1.3 2007/08/19 10:37:02 tnn2 Exp $
#

DISTNAME=		aircrack-ng-0.9.1
CATEGORIES=		security
MASTER_SITES=		http://download.aircrack-ng.org/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.aircrack-ng.org/
COMMENT=		Tools for auditing wireless networks

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
# Override SBINFILES. The other tools have not been ported yet.
MAKE_ENV+=	SBINFILES=airodump-ng
PLIST_SUBST+=	notyet="@comment "
.else
PLIST_SUBST+=	notyet=""
.endif

.include "../../mk/bsd.pkg.mk"
