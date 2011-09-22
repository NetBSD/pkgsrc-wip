# $NetBSD: Makefile,v 1.2 2011/09/22 03:01:33 ryo-on Exp $
#

DISTNAME=	clojure-contrib-1.2.0
CATEGORIES=	lang
MASTER_SITES=	http://github.com/downloads/clojure/clojure-contrib/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://clojure.org/
COMMENT=	Extensions and enhancements to the Clojure libraries
#LICENSE=	eclipse-1.0 # http://opensource.org/licenses/eclipse-1.0.php

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS=	clojure>=1.2.0:../../wip/clojure

# Force using "curl" for fetching the distribution file. It is only available
# over HTTPS and "curl" is the only fetch program which always supports HTTPS.
FETCH_USING=	curl

NO_BUILD=	yes
USE_LANGUAGES=	# none

INSTALLATION_DIRS=	lib/java/clojure share/doc/${PKGNAME_NOREV}

do-install:
	${INSTALL_DATA} ${WRKSRC}/target/${PKGNAME_NOREV}.jar \
		${DESTDIR}${PREFIX}/lib/java/clojure/clojure-contrib.jar
	${INSTALL_DATA} ${WRKSRC}/README.txt \
		${DESTDIR}${PREFIX}/share/doc/${PKGNAME_NOREV}

.include "../../mk/bsd.pkg.mk"
