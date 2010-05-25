# $NetBSD: Makefile,v 1.2 2010/05/25 15:56:04 cheusov Exp $
#

DISTNAME=	makedict-0.4.1-beta1-Source
PKGNAME=	${DISTNAME:S/-Source//:S/-beta/beta/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xdxf/}

MAINTAINER=	vle@gmx.net
HOMEPAGE=	http://sourceforge.net/projects/xdxf/
COMMENT=	Dictionary converting tool

LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_CMAKE=		yes
USE_TOOLS=		pkg-config

USE_LANGUAGES=		c c++
INSTALLATION_DIRS+=	share/doc/makedict
DOCS=			AUTHORS ChangeLog NEWS README TODO
DOCDIR=			${PREFIX}/share/doc/makedict

TEST_TARGET=		test

post-install:
.for doc in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DESTDIR}${DOCDIR}
.endfor

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
