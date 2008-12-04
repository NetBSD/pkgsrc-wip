# $NetBSD: Makefile,v 1.6 2008/12/04 22:49:51 tnn2 Exp $
#

DISTNAME=		aircrack-ng-1.0-rc1
PKGNAME=		aircrack-ng-1.0rc1
CATEGORIES=		security
MASTER_SITES=		http://download.aircrack-ng.org/

MAINTAINER=		tnn@NetBSD.org
HOMEPAGE=		http://www.aircrack-ng.org/
COMMENT=		Tools for auditing wireless networks

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		common.mak
SUBST_SED.fix-paths=		-e 's,/usr/local,${PREFIX},g'
SUBST_SED.fix-paths+=		-e 's,man/man1,${PKGMANDIR}/man1,g'

CHECK_INTERPRETER_SKIP=		sbin/airdriver-ng # xxx might as well not install it

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
