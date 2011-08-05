# $NetBSD: Makefile,v 1.7 2011/08/05 15:56:08 asau Exp $
VERSION=	1.2.3
DATERELEASE=    20110315
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

NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_TOOLS+= 	perl
USE_TOOLS+=     gmake
RUBY_REQD=	1.8.7
RUBY_VERSION=   ${RUBY18_VERSION}
RUBY_VERSION_SUPPORTED= 18
#REPLACE_RUBY_DIRS=	bin
#USE_RUBY_SETUP=	yes
USE_LANGUAGES+=	c c++
# DESTDIR=${LOCALBASE}	FIXME!

WRKSRC=		${WRKDIR}/rubinius-${VERSION}
pre-patch:
        if ${TEST} ! -f /usr/include/llvm; then \
	 ln -s /usr/pkg/include/llvm /usr/include/llvm \
        fi; # Evil hack. Please fix

do-install:
	if ${TEST} -f ${DESTDIR}/bin/rake18; then \
	 if ${TEST} ! -f ${DESTDIR}/bin/rake; then \
		ln -s ${DESTDIR}/bin/rake18 ${DESTDIR}/bin/rake; \
	 fi; \
	fi;
	cd work/rubinius-${VERSION} && ./configure --prefix=${DESTDIR}/rubinius && ${DESTDIR}/bin/rake install

DEPENDS+=	bison>=2.4.3:../../devel/bison
DEPENDS+=	zlib>=1.2.3:../../devel/zlib
DEPENDS+=	ruby>=1.8.7:../../lang/ruby
DEPENDS+=	llvm>=2.8:../../wip/llvm28
DEPENDS+=	${RUBY_PKGPREFIX}-rubygems>=1.3.7:../../misc/rubygems
DEPENDS+=	${RUBY_PKGPREFIX}-rake>=0.8.3:../../devel/rake

SO_SUFFIX=		so
RUBY_NAME=		ruby18
PLIST_SUBST+=		SO_SUFFIX=${SO_SUFFIX}
PLIST_SUBST+=		RUBY_NAME=${RUBY_NAME}

.include "../../devel/readline/buildlink3.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
