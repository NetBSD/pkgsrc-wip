# $NetBSD: Makefile,v 1.11 2012/05/24 06:12:13 thomasklausner Exp $
VERSION=	1.2.4
DATERELEASE=    20110705
DISTNAME=	rubinius-${VERSION}-${DATERELEASE}
CATEGORIES=	lang
MASTER_SITES=	http://asset.rubini.us/

MAINTAINER=	ober@NetBSD.org
HOMEPAGE=	http://rubini.us/
COMMENT=	Rubinius is an implementation of the Ruby programming language
EXTRACT_SUFX=	.tar.gz

PKG_DESTDIR_SUPPORT=	user-destdir
LICENSE=       modified-bsd

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+= 	perl
USE_TOOLS+=     gmake rake
RUBY_REQD=	1.8.7
RUBY_VERSION=   ${RUBY18_VERSION}
RUBY_VERSION_SUPPORTED= 18
RAKE_NAME=	rake18
USE_LANGUAGES+=	c c++
WRKSRC=		${WRKDIR}/rubinius-${VERSION}
CONFIG_SHELL= 	$(RUBY)

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT= 	${WRKSRC}/configure
CONFIGURE_ARGS=		-P ${PREFIX}/rubinius

do-build:
	cd ${WRKSRC} && ${RAKE_NAME} build

do-install:
	cd ${WRKSRC} && ${RAKE_NAME} install

DEPENDS+=	bison>=2.4.3:../../devel/bison
DEPENDS+=	zlib>=1.2.3:../../devel/zlib
DEPENDS+=	ruby>=1.8.7:../../lang/ruby
DEPENDS+=	clang>=2.8:../../lang/clang
DEPENDS+=	${RUBY_PKGPREFIX}-rubygems>=1.3.7:../../misc/rubygems
DEPENDS+=	${RUBY_PKGPREFIX}-rake>=0.8.3:../../devel/rake

SO_SUFFIX=		so
RUBY_NAME=		ruby18
PLIST_SUBST+=		SO_SUFFIX=${SO_SUFFIX}
PLIST_SUBST+=		RUBY_NAME=${RUBY_NAME}

.include "../../devel/readline/buildlink3.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
 
