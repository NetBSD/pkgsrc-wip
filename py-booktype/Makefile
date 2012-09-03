# $NetBSD: Makefile,v 1.1 2012/09/03 23:10:51 jihbed Exp $
#

DISTNAME=	Booktype-1.5
PKGNAME=	${PYPKGPREFIX}-booktype-1.5
CATEGORIES=	textproc
MASTER_SITES=	http://pypi.python.org/packages/source/B/Booktype/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://booki-dev.flossmanuals.net/
COMMENT= FLOSS Manuals collaborative book writing tool
LICENSE=	gnu-gpl-v3


DEPENDS+=	p5-Text-Aspell>=0.09:../../textproc/p5-Text-Aspell
DEPENDS+=	p5-Encode>=2.44:../../textproc/p5-Encode
DEPENDS+=	p5-XML-DOM>=1.44:../../textproc/p5-XML-DOM

DEPENDS+=	${PYPKGPREFIX}-simplejson>=2.6.0:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-feedparser>=5.1.2:../../textproc/py-feedparser
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-Unidecode>=0.04.9:../../textproc/py-Unidecode
DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/Booktype-1.5

USE_TOOLS+=	perl
USE_LANGUAGES=	# none

REPLACE_INTERPRETER+=	perl
REPLACE.perl.old=	.*/bin/perl
REPLACE.perl.new=	${PERL5}
REPLACE_FILES.perl=	${WRKSRC}/lib/booki/site_static/xinha/plugins/SpellChecker/spell-check-logic.cgi

REPLACE_INTERPRETER+=	python
REPLACE.python.old=	/usr/bin/env
REPLACE.python.new=	${PYTHONBIN}
REPLACE_FILES.python=	${WRKSRC}/lib/sputnik/redis-backuo.py


REPLACE_INTERPRETER+=	python
REPLACE.python.old=	/usr/bin/env
REPLACE.python.new=	${PYTHONBIN}
REPLACE_FILES.python=	${WRKSRC}/lib/booki/manage.py

PYTHON_VERSIONS_ACCEPTED= 27 26 25

.include "options.mk"

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
