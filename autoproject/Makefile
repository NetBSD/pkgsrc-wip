# $NetBSD: Makefile,v 1.3 2004/01/22 20:36:05 rillig Exp $

DISTNAME=		autoproject-0.17
CATEGORIES=		devel
MASTER_SITES=		http://www.mv.com/ipusers/vanzandt/ \
			http://www.ibiblio.org/pub/Linux/devel/

MAINTAINER=		benedikt.meurer@unix-ag.uni-siegen.de
HOMEPAGE=		http://www.mv.com/ipusers/vanzandt/
COMMENT=		Creates a skeleton source package for a new program

DEPENDS+=		autoconf>=2.57:../../devel/autoconf
DEPENDS+=		automake>=1.7:../../devel/automake
DEPENDS+=		bash>=2.0:../../shells/bash2
DEPENDS+=		{sh-utils-[0-9]*,coreutils-[0-9]*}:../../sysutils/coreutils

GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
