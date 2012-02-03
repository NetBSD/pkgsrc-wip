# $NetBSD: Makefile,v 1.8 2012/02/03 15:20:19 ryo-on Exp $
#

DISTNAME=	dos2unix-5.3.2
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dos2unix/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://waterlan.home.xs4all.nl/dos2unix.html
COMMENT=	Convert text files with DOS or Mac line endings to Unix line endings
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	unix2dos-[0-9]*

USE_TOOLS+=	gmake msgfmt xgettext perl

BUILD_MAKE_FLAGS+=	LDFLAGS_EXTRA+=-lintl
INSTALL_MAKE_FLAGS+=	prefix=${PREFIX}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
