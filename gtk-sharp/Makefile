# $NetBSD: Makefile,v 1.1.1.1 2003/03/24 22:44:54 marc Exp $
#

DISTNAME=	gtk-sharp-0.8
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtk-sharp/}

MAINTAINER=	marc@informatik.uni-bremen.de
HOMEPAGE=	http://gtk-sharp.sourceforge.net/
COMMENT=	.Net language binding for gtk+

DEPENDS+=	p5-XML-LibXML>=1.31:../../textproc/p5-XML-LibXML

USE_BUILDLINK2=	YES
USE_GMAKE=	YES
USE_PERL5=	YES
USE_X11=	YES
USE_LIBTOOL=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=	YES
PERL5_SITELIB=	YES

PARSER_MK=	${WRKSRC}/parser/Makefile.in

post-patch:
	${SED} -e 's,%%PERL5_SITELIB%%,${PERL5_SITELIB},' \
		${PARSER_MK} > ${PARSER_MK}.new
	${MV} ${PARSER_MK}.new ${PARSER_MK}

do-build:
	cd ${WRKSRC} && ${GMAKE} -f makefile

do-install:
	cd ${WRKSRC} && ${GMAKE} -f makefile install

.include "../../databases/libgnomedb/buildlink2.mk"
.include "../../lang/mono/buildlink2.mk"
.include "../../www/libgtkhtml/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
