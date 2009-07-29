# $NetBSD: Makefile,v 1.8 2009/07/29 08:58:57 jihbed Exp $

DISTNAME=		autoproject-0.20
CATEGORIES=		devel
MASTER_SITES=		http://jrv.oddones.org/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://jrv.oddones.org/
COMMENT=		Creates a skeleton source package for a new program

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		autoconf>=2.57:../../devel/autoconf
DEPENDS+=		automake>=1.7:../../devel/automake
DEPENDS+=		bash>=2.0:../../shells/bash2
DEPENDS+=		{sh-utils-[0-9]*,coreutils-[0-9]*}:../../sysutils/coreutils

GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
