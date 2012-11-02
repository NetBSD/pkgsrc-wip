# $NetBSD: Makefile,v 1.5 2012/11/02 15:00:55 lexort Exp $

DISTNAME=	swig-2.0.8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=swig/}

# 2012-10: gnuradio is said to work with swig2 (private communication
# by gdt@ with a GNU Radio developer).

# TODO: check x11/ruby-wxruby for working with swig2, but this is not
# a bar to importing it.

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://www.swig.org/
COMMENT=	Simplified Wrapper and Interface Generator
LICENSE=	2-clause-bsd

CONFLICTS=		swig-build-[0-9]*

CONFIGURE_ARGS+=	--with-swiglibdir=${PREFIX}/share/swig/1.3
BUILD_TARGET=		swig

USE_TOOLS+=		gmake pax
GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES

INSTALLATION_DIRS+=	share/doc/swig share/examples/swig

CHECK_INTERPRETER_SKIP+=	share/examples/swig/*

# configure fails to generate this on NetBSD
LDFLAGS+=	-lpcre

TEST_TARGET=	check
# Tests require lots of other dependencies.  There should be a better
# way to encode this, but for now they are commented out -gdt.
#.include "../../lang/python/extension.mk"
#.include "../../lang/php53/buildlink3.mk"
#.include "../../devel/boost-libs/buildlink3.mk"

post-install:
	cd ${WRKSRC}/Doc/Manual && \
	${INSTALL_DATA} SWIGDocumentation.html SWIGDocumentation.pdf	\
		*.png ${DESTDIR}${PREFIX}/share/doc/swig
	cd ${WRKSRC}/Examples &&					\
	pax -wr								\
		-s ',.*CVS.*,,'						\
		-s ',.*Makefile\.in$$,,'				\
		-s ',^test-suite.*,,'					\
		. ${DESTDIR}${PREFIX}/share/examples/swig

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
