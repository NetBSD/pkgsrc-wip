# $NetBSD: Makefile,v 1.9 2004/08/17 18:27:56 tvierling Exp $

DISTNAME=	kapital-1.1.030606
CATEGORIES=	devel kde

MAINTAINER=	greyskyy@users.sourceforge.net
HOMEPAGE=	http://www.thekompany.com/products/kapital/
COMMENT=	Personal finance manager

USE_BUILDLINK3=	YES

DOWNLOAD_PAGE=	http://www.thekompany.com/products/

LICENSE=		no-redistribution
RESTRICTED=		"Redistribution not permitted"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

INTERACTIVE_STAGE=	fetch
_FETCH_MESSAGE= \
	${ECHO} "======================================================================"; \
	${ECHO} ; \
	${ECHO} " The file ${DISTNAME}${EXTRACT_SUFX} containing the"; \
	${ECHO} " Kapital source code must be downloaded "; \
	${ECHO} " into:"; \
	${ECHO} "	${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}"; \
	${ECHO} " from:"; \
	${ECHO} "	${DOWNLOAD_PAGE}"; \
	${ECHO} ; \
	${ECHO} " Choose 'Download version' from the Kapital section, add it to"; \
	${ECHO} "  your cart, checkout, registering if needed.  Once you get to "; \
	${ECHO} "  the downloads page, select the 'Source Download' item from the";\
	${ECHO} "  top of the list."; \
	${ECHO} ; \
	${ECHO} "======================================================================"

USE_GNU_TOOLS+=	make
GNU_CONFIGURE=  YES
USE_LIBTOOL=    YES
LIBTOOL_LA_FILES+=	lib/libaccountcombo.la
LIBTOOL_LA_FILES+=	lib/libaccountlist.la
LIBTOOL_LA_FILES+=	lib/libaccountsbox.la
LIBTOOL_LA_FILES+=	lib/libaddressbook.la
LIBTOOL_LA_FILES+=	lib/libbaseipagewidget.la
LIBTOOL_LA_FILES+=	lib/libcalc.la
LIBTOOL_LA_FILES+=	lib/libcalendar.la
LIBTOOL_LA_FILES+=	lib/libcategorylist.la
LIBTOOL_LA_FILES+=	lib/libcheckwriter.la
LIBTOOL_LA_FILES+=	lib/libcontrolbar.la
LIBTOOL_LA_FILES+=	lib/libcorepages.la
LIBTOOL_LA_FILES+=	lib/libeditcontrol.la
LIBTOOL_LA_FILES+=	lib/libfindtransaction.la
LIBTOOL_LA_FILES+=	lib/libfmengine.la
LIBTOOL_LA_FILES+=	lib/libfmfile.la
LIBTOOL_LA_FILES+=	lib/libimportdialog.la
LIBTOOL_LA_FILES+=	lib/libkapitalcore.la
LIBTOOL_LA_FILES+=	lib/liblistbox.la
LIBTOOL_LA_FILES+=	lib/libmaincaption.la
LIBTOOL_LA_FILES+=	lib/libmyfinances.la
LIBTOOL_LA_FILES+=	lib/libofx.la
LIBTOOL_LA_FILES+=	lib/libonlinestatement.la
LIBTOOL_LA_FILES+=	lib/libpaintwidget.la
LIBTOOL_LA_FILES+=	lib/libreconcilie.la
LIBTOOL_LA_FILES+=	lib/libregister.la
LIBTOOL_LA_FILES+=	lib/libreport.la
LIBTOOL_LA_FILES+=	lib/libschedulerpage.la
LIBTOOL_LA_FILES+=	lib/libtoolbar.la
LTCONFIG_OVERRIDE=  ${WRKSRC}/ltconfig
SHLIBTOOL_OVERRIDE=	libtool

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
