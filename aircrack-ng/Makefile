# $NetBSD: Makefile,v 1.8 2009/03/22 19:21:27 moubctez Exp $

DISTNAME=		aircrack-ng-1.0-rc2
PKGNAME=		aircrack-ng-1.0rc2
CATEGORIES=		security
MASTER_SITES=		http://download.aircrack-ng.org/

MAINTAINER=		tnn@NetBSD.org
HOMEPAGE=		http://www.aircrack-ng.org/
COMMENT=		Tools for auditing wireless networks

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake

DEPENDS+=		bash>=3.2.9:../../shells/bash

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	.*/bin/bash
REPLACE.bash.new=	${PREFIX}/bin/bash
REPLACE_FILES.bash=	airdriver-ng

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
