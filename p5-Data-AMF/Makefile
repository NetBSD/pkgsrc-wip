# $NetBSD: Makefile,v 1.1.1.1 2011/10/27 20:38:45 tomasbodzar Exp $
#

DISTNAME=	Data-AMF-0.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-AMF/lib/Data/AMF.pm
COMMENT=	serialize/deserialize Adobe Action Message Format data
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	groff
DEPENDS+=	p5-Any-Moose*:../../devel/p5-Any-Moose
DEPENDS+=	p5-DateTime*:../../time/p5-DateTime
DEPENDS+=	p5-UNIVERSAL-require*:../../devel/p5-UNIVERSAL-require
DEPENDS+=	p5-XML-LibXML*:../../textproc/p5-XML-LibXML

.include "../../lang/perl5/module.mk"
# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
