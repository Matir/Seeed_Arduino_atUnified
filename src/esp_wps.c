/*
 *  The MIT License (MIT)
 *  Copyright (C) 2019-2020  Seeed Technology Co.,Ltd.
 */
#include "esp_wps.h"
#include "esp_at_lib.h"


/**
  * @brief     Enable Wi-Fi WPS function.
  *
  * @attention WPS can only be used when ESP32 station is enabled.
  *
  * @param     wps_type_t wps_type : WPS type, so far only WPS_TYPE_PBC and WPS_TYPE_PIN is supported
  *
  * @return    
  *          - ESP_OK : succeed
  *          - ESP_ERR_WIFI_WPS_TYPE : wps type is invalid
  *          - ESP_ERR_WIFI_WPS_MODE : wifi is not in station mode or sniffer mode is on
  *          - ESP_FAIL : wps initialization fails
  */
esp_err_t esp_wifi_wps_enable(const esp_wps_config_t *config) {
	espr_t r;

	printf("%s() +++ L%d\r\n", __func__, __LINE__);

	r = esp_wps_configure(1, NULL, NULL, true);
	if (r != espOK) {
		return -1;
	}
	return ESPR_TO_ESP_ERR(r);
}

/**
  * @brief  Disable Wi-Fi WPS function and release resource it taken.
  *
  * @param  null
  *
  * @return    
  *          - ESP_OK : succeed
  *          - ESP_ERR_WIFI_WPS_MODE : wifi is not in station mode or sniffer mode is on
  */
esp_err_t esp_wifi_wps_disable(void) {
	espr_t r;

	printf("%s() +++ L%d\r\n", __func__, __LINE__);

	r = esp_wps_configure(0, NULL, NULL, true);
	if (r != espOK) {
		return -1;
	}
	return ESPR_TO_ESP_ERR(r);
}

/**
  * @brief     WPS starts to work.
  *
  * @attention WPS can only be used when ESP32 station is enabled.
  *
  * @param     timeout_ms : maximum blocking time before API return.
  *          - 0 : non-blocking
  *          - 1~120000 : blocking time (not supported in IDF v1.0)
  *
  * @return    
  *          - ESP_OK : succeed
  *          - ESP_ERR_WIFI_WPS_TYPE : wps type is invalid
  *          - ESP_ERR_WIFI_WPS_MODE : wifi is not in station mode or sniffer mode is on
  *          - ESP_ERR_WIFI_WPS_SM : wps state machine is not initialized
  *          - ESP_FAIL : wps initialization fails
  */
esp_err_t esp_wifi_wps_start(int timeout_ms) {
	return ESP_OK;
}