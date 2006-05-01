# $NetBSD: Makefile,v 1.5 2006/05/01 14:20:07 shattered Exp $

DISTNAME=		autoproject-0.17
CATEGORIES=		devel
MASTER_SITES=		http://jrv.oddones.org

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://jrv.oddones.org
COMMENT=		Creates a skeleton source package for a new program

DEPENDS+=		autoconf>=2.57:../../devel/autoconf
DEPENDS+=		automake>=1.7:../../devel/automake
DEPENDS+=		bash>=2.0:../../shells/bash2
DEPENDS+=		{sh-utils-[0-9]*,coreutils-[0-9]*}:../../sysutils/coreutils

GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
