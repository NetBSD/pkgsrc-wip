# $NetBSD: Makefile,v 1.1 2011/01/23 06:59:38 jafour1 Exp $
DISTNAME=	rubinius-1.2.1dev
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/misc/ober/

MAINTAINER=	ober@netbsd.org
HOMEPAGE=	http://rubini.us/
COMMENT=	Rubinius is an implementation of the Ruby programming language.
EXTRACT_SUFX=	.tgz


PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_TOOLS+= 	perl 
RUBY_REQD=	1.8.7
RUBY_VERSION=   ${RUBY18_VERSION}
RUBY_VERSION_SUPPORTED= 18
#REPLACE_RUBY_DIRS=	bin
USE_RUBY_SETUP=	yes
USE_LANGUAGES+=	c c++ ruby
DESTDIR=${LOCALBASE}

do-install:
	if test -f ${DESTDIR}/bin/rake18; then \
	 if test ! -f ${DESTDIR}/bin/rake; then \
		ln -s ${DESTDIR}/bin/rake18 ${DESTDIR}/bin/rake; \
	 fi; \
	fi;
	cd ${WRKSRC} && ./configure --prefix=${DESTDIR}/rubinius && ${DESTDIR}/bin/rake install



DEPENDS+=	bison>=2.4.3:../../devel/bison
DEPENDS+=	zlib>=1.2.3:../../devel/zlib
DEPENDS+=	gmake>=3.81:../../devel/gmake
DEPENDS+=	ruby>=1.8.7:../../lang/ruby
DEPENDS+=	llvm>=2.8:../../wip/llvm28
DEPENDS+=	${RUBY_PKGPREFIX}-rubygems>=1.3.7:../../misc/rubygems
DEPENDS+=	${RUBY_PKGPREFIX}-rake>=0.8.3:../../devel/rake

SO_SUFFIX=		so
RUBY_NAME=		ruby18
PLIST_SUBST+=   	SO_SUFFIX=${SO_SUFFIX}
PLIST_SUBST+=   	RUBY_NAME=${RUBY_NAME}

.include "../../devel/readline/buildlink3.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

