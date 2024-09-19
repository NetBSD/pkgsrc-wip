# $NetBSD$

DISTNAME=	gscan2pdf-2.9.1
CATEGORIES=	perl5 graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gscan2pdf/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/gscan2pdf/files/gscan2pdf/2.9.1/
COMMENT=	GUI for producing a multipage PDF from a scan
LICENSE=	gnu-gpl-v3 # icons/180_degree.svg + all the unmentioned files
LICENSE+=	AND gnu-gpl-v2 # icons/scanner.svg
LICENSE+=	AND gnu-lgpl-v2.1 # icons/pdf.svg
# LICENSE+=	AND cc0 # net.sourceforge.gscan2pdf.appdata.xml

DEPENDS+=	p5-Config-General>=2.4:../../devel/p5-Config-General
DEPENDS+=	p5-Date-Calc>=0:../../devel/p5-Date-Calc
DEPENDS+=	p5-Filesys-Df>=0:../../sysutils/p5-Filesys-Df
DEPENDS+=	p5-Gtk3-SimpleList>=0:../../x11/p5-Gtk3-SimpleList
DEPENDS+=	p5-PerlMagick>=0:../../graphics/p5-PerlMagick
DEPENDS+=	p5-Image-Sane>=0:../../graphics/p5-Image-Sane
DEPENDS+=	p5-List-MoreUtils>=0:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Log-Log4perl>=0:../../devel/p5-Log-Log4perl
DEPENDS+=	p5-PDF-API2>=0:../../textproc/p5-PDF-API2
DEPENDS+=	p5-Readonly>=0:../../devel/p5-Readonly
DEPENDS+=	p5-Set-IntSpan>=1.1:../../devel/p5-Set-IntSpan
DEPENDS+=	p5-Sub-Override>=0:../../devel/p5-Sub-Override
DEPENDS+=	p5-Try-Tiny>=0:../../devel/p5-Try-Tiny

USE_TOOLS+=	gmake

PERL5_PACKLIST=		auto/gscan2pdf/.packlist
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

.include "../../graphics/p5-goocanvas2/buildlink3.mk"
.include "../../x11/p5-gtk3/buildlink3.mk"
.include "../../devel/p5-glib2/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
