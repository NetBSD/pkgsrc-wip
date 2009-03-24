# $NetBSD: Makefile,v 1.9 2009/03/24 19:57:10 absd Exp $

DISTNAME=		aircrack-ng-1.0-rc2
PKGNAME=		aircrack-ng-1.0rc2
CATEGORIES=		security
MASTER_SITES=		http://download.aircrack-ng.org/

MAINTAINER=		tnn@NetBSD.org
HOMEPAGE=		http://www.aircrack-ng.org/
COMMENT=		Tools for auditing wireless networks

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS+=	bin sbin ${PKGMANDIR}/man1

USE_TOOLS+=		gmake

DEPENDS+=		bash>=3.2.9:../../shells/bash

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	.*/bin/bash
REPLACE.bash.new=	${PREFIX}/bin/bash
REPLACE_FILES.bash=	airdriver-ng

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
