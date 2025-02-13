# $NetBSD: Makefile,v 1.0 2024/12/05 14:00:00 dkazankov Exp $

PKGNAME=	gnat-glade-6.0.1
CATEGORIES=	devel
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/gnat-glade/
COMMENT=	GNAT Library for Ada Distributed Environment
LICENSE=	gnu-gpl-v2

DISTNAME=	gnat-glade-code-r135-trunk
DISTFILES=	${DISTNAME}.zip

SITES.${DISTNAME}.zip=	-https://sourceforge.net/code-snapshots/svn/g/gn/gnat-glade/code/gnat-glade-code-r135-trunk.zip

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

CHECK_PIE_SKIP+=	bin/*
CHECK_RELRO_SKIP+=	bin/*

USE_LANGUAGES=	c ada

GCC_REQD+=	13

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} bin include lib \( -type f -or -type l \) -print | ${SORT};

.include "../../mk/bsd.prefs.mk"

post-patch:
	chmod +x ${WRKSRC}/Dist/config.sdefault

.include "../../lang/gcc13-gnat-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
