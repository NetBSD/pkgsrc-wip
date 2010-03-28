# $NetBSD: Makefile,v 1.1.1.1 2010/03/28 11:48:07 ryo-on Exp $
#

DISTNAME=	llgal-0.13.16
CATEGORIES=	www graphics
MASTER_SITES=	http://download.gna.org/llgal/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://home.gna.org/llgal/
COMMENT=	The llgal is an easy and fast on-line static gallery generator

LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

USE_TOOLS+=	gmake perl:run
PERL5_MODULE_TYPE=	MakeMaker
PERL5_PACKLIST=	auto/Llgal/.packlist

DEPENDS+=	p5-Image-ExifTool-[0-9]*:../../graphics/p5-Image-ExifTool
DEPENDS+=	p5-Image-Size-[0-9]*:../../graphics/p5-Image-Size
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-gettext-[0-9]*:../../devel/p5-gettext

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		Makefile
SUBST_SED.fix-paths=		-e 's,/usr/local,${PREFIX},g'

SUBST_CLASSES+=			interpreter
SUBST_STAGE.interpreter=	pre-configure
SUBST_MESSAGE.interpreter=	Fixing absolute path of interpreter.
SUBST_FILES.interpreter=	llgal.in
SUBST_SED.interpreter=		-e 's,/usr/bin/perl,${PREFIX}/bin/perl,g'

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
