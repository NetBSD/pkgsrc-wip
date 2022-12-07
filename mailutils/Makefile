# $NetBSD: Makefile,v 1.3 2017/08/14 09:00:06 ecbrown Exp $

DISTNAME=	mailutils-3.15
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.gnu.org/gnu/mailutils/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mailutils.org/
COMMENT=	Utilities, daemons, and filters for processing e-mail
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v3

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--infodir=${PREFIX}/${PKGINFODIR}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--without-gnutls
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--without-guile
CONFIGURE_ARGS+=	--without-gdbm
CONFIGURE_ARGS+=	--without-tcp-wrappers
CONFIGURE_ARGS+=	--without-ldap

INFO_FILES=	yes

SUBST_CLASSES+=		iconv
SUBST_STAGE.iconv=	pre-configure
SUBST_MESSAGE.iconv=	Do not require lib/charset.alias.
SUBST_FILES.iconv+=	lib/gnu/Makefile.in
SUBST_SED.iconv=	-e '/need_charset_alias=/s|true|false|'

.include "../../converters/libiconv/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
