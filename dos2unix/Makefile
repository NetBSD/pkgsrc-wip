# $NetBSD: Makefile,v 1.1.1.1 2011/02/11 00:09:13 ryo-on Exp $
#

DISTNAME=	dos2unix-5.2
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dos2unix/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.xs4all.nl/~waterlan/dos2unix.html
COMMENT=	Convert text files with DOS or Mac line endings to Unix line endings
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake msgfmt xgettext perl

BUILD_MAKE_FLAGS+=	prefix=${PREFIX} \
			mandir=man \
			LDFLAGS_EXTRA+=-lintl

INSTALL_MAKE_FLAGS+=	prefix=${PREFIX}
#INSTALL_MAKE_FLAGS+=	mandir=${DESTDIR}${PREFIX}${PKGMANDIR}
#INSTALL_MAKE_FLAGS+=	mandir=${PREFIX}${PKGMANDIR}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
