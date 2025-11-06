# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.py-electrum
PKG_SUPPORTED_OPTIONS=		x11 hardware zbar
PKG_SUGGESTED_OPTIONS=		x11 zbar

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
DEPENDS+=	${PYPKGPREFIX}-qt6>=6.9.0:../../x11/py-qt6
DEPENDS+=	${PYPKGPREFIX}-qdarkstyle>=3.2:../../wip/py-qdarkstyle
.endif

.if !empty(PKG_OPTIONS:Mhardware)
DEPENDS+=	${PYPKGPREFIX}-trezor>=0.13.0:../../security/py-trezor
DEPENDS+=	${PYPKGPREFIX}-mnemonic>=0.8:../../devel/py-mnemonic
DEPENDS+=	${PYPKGPREFIX}-cbor2>=5.4.6:../../devel/py-cbor2
DEPENDS+=	${PYPKGPREFIX}-serial>=3.5.0:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-hidapi>=0.14.0:../../wip/py-hidapi
DEPENDS+=	${PYPKGPREFIX}-bitbox02>=7.0.0:../../wip/py-bitbox02
DEPENDS+=	${PYPKGPREFIX}-ckcc-protocol>=0.7.7:../../wip/py-ckcc-protocol
DEPENDS+=	${PYPKGPREFIX}-ledger-bitcoin>=0.2.0:../../wip/py-ledger-bitcoin
.endif

.if !empty(PKG_OPTIONS:Mzbar)
.include "../../graphics/zbar/buildlink3.mk"
.endif
