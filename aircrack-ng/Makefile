# $NetBSD: Makefile,v 1.5 2008/02/25 11:12:40 tnn2 Exp $
#

DISTNAME=		aircrack-ng-0.9.3
CATEGORIES=		security
MASTER_SITES=		http://download.aircrack-ng.org/

MAINTAINER=		tnn@NetBSD.org
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
