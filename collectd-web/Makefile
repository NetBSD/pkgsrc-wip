# $NetBSD$

DISTNAME=	collectd-web-0.4.1
CATEGORIES=	www
GITHUB_PROJECT=	collectd-web
MASTER_SITES=	${MASTER_SITE_GITHUB:=httpdss/}
EXTRACT_SUFX=	.zip

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/httpdss/
COMMENT=	Web interface for Collectd	
LICENSE=	gnu-gpl-v2

NO_CONFIGURE=		yes
NO_BUILD=		yes
USE_TOOLS+=		pax unzip
AUTO_MKDIRS=		yes
#EXTRACT_ONLY=		# empty
REPLACE_PERL+=		cgi-bin/*.pl
REPLACE_PERL+=		cgi-bin/*.cgi
INSTALLATION_DIRS=	share/collectd-web

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_LANGUAGES=	# none

DEPENDS+=	fcgiwrap>=1.1.0:../../www/fcgiwrap
DEPENDS+=	spawn-fcgi>=1.6.3:../../www/spawn-fcgi
DEPENDS+=	p5-HTTP-Parser>=0.06:../../www/p5-HTTP-Parser
DEPENDS+=	p5-JSON>=2.94:../../converters/p5-JSON
DEPENDS+=	p5-RRD-Simple>=1.44:../../databases/p5-RRD-Simple
DEPENDS+=	p5-CGI>=4.36:../../www/p5-CGI
#DEPENDS+=	cgic>=2.02:../../www/cgic
#DEPENDS+=	fcgi>=2.4.0:../../www/fcgi

do-install:
	cd ${WRKSRC} && pax -rw -pe . ${DESTDIR}${PREFIX}/${INSTALLATION_DIRS}

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
