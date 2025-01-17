# HAL packages
ifneq ($(BOARD_VENDOR_QCOM_GPS_LOC_API_HARDWARE),)

# GPS-HIDL
LOC_BOARD_PLATFORM_LIST += msm8937
LOC_BOARD_PLATFORM_LIST += msm8953
LOC_BOARD_PLATFORM_LIST += msm8998
LOC_BOARD_PLATFORM_LIST += apq8098_latv
LOC_BOARD_PLATFORM_LIST += sdm710
LOC_BOARD_PLATFORM_LIST += qcs605
LOC_BOARD_PLATFORM_LIST += sdm845
LOC_BOARD_PLATFORM_LIST += sdm660
LOC_BOARD_PLATFORM_LIST += msmnile
LOC_BOARD_PLATFORM_LIST += sdmshrike
LOC_BOARD_PLATFORM_LIST += $(MSMSTEPPE)
LOC_BOARD_PLATFORM_LIST += $(TRINKET)
LOC_BOARD_PLATFORM_LIST += kona
LOC_BOARD_PLATFORM_LIST += atoll
LOC_BOARD_PLATFORM_LIST += lito
LOC_BOARD_PLATFORM_LIST += bengal
LOC_BOARD_PLATFORM_LIST += lahaina
LOC_BOARD_PLATFORM_LIST += holi
LOC_BOARD_PLATFORM_LIST += monaco

# Add product packages
ifneq (,$(filter $(LOC_BOARD_PLATFORM_LIST),$(TARGET_BOARD_PLATFORM)))

PRODUCT_PACKAGES += gps.conf
PRODUCT_PACKAGES += flp.conf
PRODUCT_PACKAGES += gnss_antenna_info.conf
PRODUCT_PACKAGES += gnss@2.0-base.policy
PRODUCT_PACKAGES += gnss@2.0-xtra-daemon.policy
PRODUCT_PACKAGES += gnss@2.0-xtwifi-client.policy
PRODUCT_PACKAGES += gnss@2.0-xtwifi-inet-agent.policy
PRODUCT_PACKAGES += libloc_pla_headers
PRODUCT_PACKAGES += liblocation_api_headers
PRODUCT_PACKAGES += libgps.utils_headers
PRODUCT_PACKAGES += liblocation_api
PRODUCT_PACKAGES += libgps.utils
PRODUCT_PACKAGES += libbatching
PRODUCT_PACKAGES += libgeofencing
PRODUCT_PACKAGES += libloc_core
PRODUCT_PACKAGES += libgnss

ifeq ($(strip $(TARGET_BOARD_AUTO)),true)
PRODUCT_PACKAGES += libgnssauto_power
endif #TARGET_BOARD_AUTO

PRODUCT_PACKAGES += android.hardware.gnss@2.1-impl-qti
PRODUCT_PACKAGES += android.hardware.gnss@2.1-service-qti

endif # ifneq (,$(filter $(LOC_BOARD_PLATFORM_LIST),$(TARGET_BOARD_PLATFORM)))
endif # ifneq ($(BOARD_VENDOR_QCOM_GPS_LOC_API_HARDWARE),)
