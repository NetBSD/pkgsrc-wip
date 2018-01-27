# $NetBSD: Makefile,v 1.3 2017/08/14 09:00:06 ecbrown Exp $

DISTNAME=	mailutils-3.2
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.gnu.org/gnu/mailutils/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mailutils.org/
COMMENT=	General-Purpose Mail Package
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--infodir=${PREFIX}/info
CONFIGURE_ARGS+=	--disable-cxx
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--without-ldap
INFO_FILES=		yes

MAKE_JOBS_SAFE=		no

_INCOMPAT_READLINE=Darwin-*-* Interix-*-*
.include "../../devel/readline/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
